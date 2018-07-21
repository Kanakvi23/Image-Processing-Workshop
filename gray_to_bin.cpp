// Convert grayscale image to binary
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    img = imread(argv[1],0);
    Mat img2;
    img2 = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));

    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
            if(img.at<uchar>(i,j)>128)
                img2.at<uchar>(i,j)=255;
            else
                img2.at<uchar>(i,j)=0;
    namedWindow("Binary",WINDOW_AUTOSIZE);
    imshow("Binary",img2);
    waitKey(0);
}
