#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int rlow,rhigh,blow,bhigh,glow,ghigh; 
Mat img;
Mat temp;

void threshcallback(int, void*)
{	
	temp = Mat(img.rows,img.cols,CV_8UC3,Scalar(255,255,255));
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
		{
			if(img.at<Vec3b>(i,j)[0]>=blow && img.at<Vec3b>(i,j)[0]<=bhigh)
			{
				if(img.at<Vec3b>(i,j)[1]>=glow && img.at<Vec3b>(i,j)[1]<=ghigh)
				{
					if(img.at<Vec3b>(i,j)[2]>=rlow && img.at<Vec3b>(i,j)[2]<=rhigh)
					{
						temp.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
						temp.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
						temp.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
					}
				}
			}
		}
	imshow("Display",temp);
	imshow("Display2",img);
	
}		

int main()
{	
	img = imread("a.png",1);
	namedWindow("Display",WINDOW_AUTOSIZE);
	createTrackbar("r-low","Display",&rlow,255,threshcallback);
	createTrackbar("r-high","Display",&rhigh,255,threshcallback);
	createTrackbar("b-low","Display",&blow,255,threshcallback);
	createTrackbar("b-high","Display",&bhigh,255,threshcallback);
	createTrackbar("g-low","Display",&glow,255,threshcallback);
	createTrackbar("g-high","Display",&ghigh,255,threshcallback);
	threshcallback(0,0);
	waitKey(0);
}
