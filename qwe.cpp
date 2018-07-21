#include "opencv2/opencv.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace cv;
using namespace std;
int t=0;
Mat img=imread("lisa.png",0);
Mat img2;
int g;
void thresh_callback(int, void *)
{
	img2=Mat(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<img2.rows;i++)
	for(int j=0;j<img2.cols;j++)
		if(g<t)
		img2.at<uchar>(i,j)=0;
		else
		img2.at<uchar>(i,j)=255;
	imshow("win",img2);
	waitKey(5);
}
int main()
{
	int ker[3][3];
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if((i+j)%2==0 && (i!=j))
	ker[i][j]=1;
	else if(i==j)
	ker[i][j]=4;
	else
	ker[i][j]=2;
	
	int gy[3][3]={{-1,2,1},{0,0,0},{1,2,1}};
	int gx[3][3]={{-1,0,1},{-2,0,2},{-3,0,3}};
	float sum=0;
	int sum1,sum2;
	int count=0;

	for(int i=0;i<img.rows;i++)
	for(int j=0;j<img.cols;j++)
	{
		sum=0;
		count=0;
		for(int k=0;k<3;k++)
		for(int l=0;l<3;l++)
		if((i+k-1)>=0 && (j+l-1)<=img.cols && (i+k-1)<=img.rows && (j+l-1)>=0)
		{
			sum+=img.at<uchar>(i+k-1,j+l-1)*ker[k][l];
			count+=ker[k][l];
		}
		img.at<uchar>(i,j)=sum/count;
	}
	
	for(int i=1;i<img.rows-1;i++)
	for(int j=1;j<img.cols-1;j++)
	{	
		sum1=0,sum2=0;
		for(int k=0;k<3;k++)
		for(int l=0;l<3;l++)
		{
			sum1+=img.at<uchar>(i+k-1,j+l-1)*gx[k][l];
			sum2+=img.at<uchar>(i+k-1,j+l-1)*gy[k][l];
		}
		g=sqrt(sum1*sum1+sum2*sum2);
	}
	namedWindow("Trackbars", WINDOW_AUTOSIZE);
	namedWindow("win", WINDOW_AUTOSIZE);
	createTrackbar("threshold","Trackbars",&t,255,thresh_callback);
	thresh_callback(0,0);
	
	waitKey(0);
	return 0;
}