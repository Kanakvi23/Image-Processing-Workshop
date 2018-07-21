#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int threshld; 
Mat img= imread("cat.jpg",2);
Mat temp = Mat(img.rows,img.cols,CV_8UC1);

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

int main()
{
	namedWindow("Display",WINDOW_AUTOSIZE);
	createTrackbar("Threshold","Display",&threshld,255,threshcallback);
	threshcallback(0,0);
	waitKey(0);
}