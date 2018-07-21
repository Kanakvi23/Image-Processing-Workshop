// Size multiplier to increase/decrease the size of the image by a multiplier
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    
    float mag;
    cout<<"Enter the maginification required"<<endl;
    cin>>mag;
    int absmag=int(sqrt(abs(mag)));

        img = imread(argv[1]);
    Mat img2 = Mat(absmag*img.rows,absmag*img.cols,CV_8UC3,Scalar(0,0,0));

    if(mag>=0)
    {
        for(int i=0;i<img2.rows;i++)
            for(int j=0;j<img2.cols;j++)
            {
                img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i/absmag,j/absmag)[0];
                img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i/absmag,j/absmag)[1];
                img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i/absmag,j/absmag)[2];
            }
    }
    else
    {
        for(int i=0;i<img2.rows;i++)
            for(int j=0;j<img2.cols;j++)
            {
                img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>((img2.rows-1-i)/absmag,(img2.cols-1-j)/absmag)[0];
                img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>((img2.rows-1-i)/absmag,(img2.cols-1-j)/absmag)[1];
                img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>((img2.rows-1-i)/absmag,(img2.cols-1-j)/absmag)[2];
            }
    }
    imshow("Magnified",img2);
    imshow("Original",img);
    waitKey(0);
}
