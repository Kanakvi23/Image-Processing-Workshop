// Histogram to show no of pixels vs intensity of pixel for grayscale image
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    Mat img;
    img = imread(argv[1],2);
    long int arr[256];
    float arr2[256];
    Mat hist = Mat(800,256*3,CV_8UC1,Scalar(255));

    for(int i=0;i<256;i++)
        arr[i]=0;

    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
            arr[img.at<uchar>(i,j)]++;


    long int max = arr[0];
    for(int i=1;i<256;i++)
        {    
            if(arr[i]>max)
                max = arr[i];
        }

    if(max>800)
        for(int i=0;i<256;i++)
            arr2[i]=arr[i]*(800.0/max); 
    else
        for(int i=0;i<256;i++)
            arr2[i]=arr[i];

    for(int j=0;j<256;j++)
        {    
            int h=799;
            for(int k=0;k<arr2[j];k++)
            {    
                hist.at<uchar>(h,j*3)=0;
                hist.at<uchar>(h,j*3+1)=0;
                h--;
            }
        }
    imshow("Histogram",hist);
    imshow("Image",img);
    waitKey(0);
}
