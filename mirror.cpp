// Create a vertical mirror image using first half of image

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    img = imread(argv[1],1);
    Mat img2= Mat(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
    int k;

    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols/2;j++)
        {
                img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
                img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
                img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
        }

    for(int i=0;i<img.rows;i++)
    {    k=1;
        for(int j=img.cols/2;j<img.cols;j++)
        {
            img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,(img.cols/2)-k)[0];
            img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,(img.cols/2)-k)[1];
            img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,(img.cols/2)-k)[2];
            k++;
        }
    }
    imshow("Result",img2);
    waitKey(0);
}
