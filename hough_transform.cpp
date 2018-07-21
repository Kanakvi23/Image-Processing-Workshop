// Hough Transform to detect lines
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stack>
#include <cmath>
#define pi 3.14

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat img = imread(argv[1],2);
    Mat img2 = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));
    
    int rmax=sqrt(pow(img.rows,2)+pow(img.cols,2));
    
    int **r_t = new int *[rmax];
    for(int i=0;i<rmax;i++)
        r_t[i]= new int[181];

    for(int r=0;r<rmax;r++)
        for(int t=0;t<181;t++)
            r_t[r][t]=0; 

    for(int i=0;i<img.rows;i++)
    {    
        for(int j=0;j<img.cols;j++)
        {    
            if(img.at<uchar>(i,j)==255)
            {
                for(int t=0;t<181;t++)
                {
                    int r=abs((i*cos(pi/180*t)+j*sin(pi/180*t)));
                    r_t[r][t]++;
                }
                
            }
        
        }
    }
    
    int thresh=80;

    for(int r=0;r<rmax;r++)
        for(int t=0;t<181;t++)
        {    
            if(r_t[r][t]>thresh)
            {     
                int max=r_t[r][t];
                int flag=0;
                for(int cntr=-8;cntr<9;cntr++)
                    for(int cntt=-8;cntt<9;cntt++)
                    {
                        if(r+cntr<0 && r+cntr>=img.rows && t+cntt<0 && t+cntt>=img.cols)
                            continue;
                        if(r_t[r+cntr][t+cntt]>max)
                            flag=1;
                    }
                if(flag==0)
                {
                    for(int i=0;i<img.rows;i++)
                        for(int j=0;j<img.cols;j++)
                            if((int)(i*cos(pi/180*t)+j*sin(pi/180*t)-r)==0)
                                {
                                    if(img.at<uchar>(i,j)==255)
                                        img2.at<uchar>(i,j)=255;
                                            
                                }
                }
            }
        }
            
    imshow("Lines Detected",img2);
    waitKey(0);
}
