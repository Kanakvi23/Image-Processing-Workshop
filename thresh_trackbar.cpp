// Using track bars to do adjust threshold in a binary image
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int threshld; 
Mat img, temp;

void threshcallback(int, void*)
{    
    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
            if(img.at<uchar>(i,j)>threshld)
                temp.at<uchar>(i,j)=255;
            else
                temp.at<uchar>(i,j)=0;
    imshow("Display",temp);
}

int main(int argc,char **argv)
{
    img = imread(argv[1],2);
temp = Mat(img.rows,img.cols,CV_8UC1);
    namedWindow("Display",WINDOW_AUTOSIZE);
    createTrackbar("Threshold","Display",&threshld,255,threshcallback);
    threshcallback(0,0);
    waitKey(0);
}
