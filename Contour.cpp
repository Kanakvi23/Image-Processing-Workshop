// Contour hvjerhv
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("try.png",1);
	Mat img_gray = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));

	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			img_gray.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3;

	Mat edges;
	Mat dst = Mat(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	blur(img_gray,edges,Size(3,3));
	Canny(edges,edges,100,100*3,3);
	img.copyTo(dst,edges);
	imshow("Canny",dst);

	vector< vector< Point > > contours;
	vector< Vec4i > hierarchy;
	findContours(edges,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_NONE);

	Mat final= Mat(img.rows,img.cols,CV_8UC1,Scalar(0));

	for(int i=0;i<contours.size();i++)
		for(int j=0;j<contours[i].size();j++)
		{
			final.at<uchar>(contours[i][j].y,contours[i][j].x)=255;
		}

	imshow("Contours",final);

	Mat poly= Mat(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<contours.size();i++)
		approxPolyDP(contours[i],contours[i],10,true);

	/*for(int i=0;i<contours.size();i++)
		for(int j=0;j<contours[i].size();j++)
		{
			poly.at<uchar>(contours[i][j].y,contours[i][j].x)=255;
		}*/
	
	RNG rng(12345);
	for(int i=0;i<contours.size();i++)
		{
			Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
			drawContours(poly,contours,i,color,2,8,hierarchy,0,Point());
		}
	imshow("Polygon",poly);
	waitKey(0);
}
