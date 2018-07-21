// Edge detection using Sobel Operator
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat img;
int threshld;

void threshcallback(int,void*)
{
    Mat img2 = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));
    int matx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int maty[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
    int gx,gy,g;
    
    for(int i=1;i<img.rows-1;i++)
        {
            for(int j=1;j<img.cols-1;j++)
            {    gy=0,gx=0;
                int cntr=1;    
                //int cntc=1;                
                for(int k=0;k<3;k++)
                {    
                    int cntc=1;
                    for(int l=0;l<3;l++)
                    {    
                        gx = gx + (img.at<uchar>(i-cntr,j-cntc)*matx[k][l]);
                        gy = gy + (img.at<uchar>(i-cntr,j-cntc)*maty[k][l]);
                        cntc--;
                    }
                    cntr--;
                }
            
                g=sqrt(pow(gx,2)+pow(gy,2));
                if(g>threshld)
                    img2.at<uchar>(i,j)=255;
                else
                    img2.at<uchar>(i,j)=0;        
            }
        }

    imshow("Display",img2);
    imshow("Original",img);
    waitKey(10);
}


int main(int argc,char **argv)
{
    img = imread(argv[1],2);
    float ker[3][3];
    float num,sum;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(((i+j)%2)==0)        
                ker[i][j]=1.0;
            else
                ker[i][j]=2.0;

    ker[1][1]=4.0;

    for(int i=0;i<img.rows;i++)
        {
            for(int j=0;j<img.cols;j++)
            {    sum=0;
                num=0;
                int cntr=1;    
                int cntc=1;
                for(int k=0;k<3;k++)
                {    
                    for(int l=0;l<3;l++)
                    {    
                        if(i-cntr<0 || i-cntr>img.rows || j-cntc<0 || j-cntc>img.cols)
                            continue;
                        sum = sum + (img.at<uchar>(i-cntr,j-cntc)*ker[k][l]);
                        num = num + ker[k][l]; 
                        cntc--;
                    } 
                    cntr--;
                }
            img.at<uchar>(i,j) = int(sum/num);
            }
        }

    namedWindow("Display",WINDOW_AUTOSIZE);
    createTrackbar("Threshold","Display",&threshld,(sqrt(8*255)),threshcallback);
    threshcallback(0,0);
    waitKey(0);
}
