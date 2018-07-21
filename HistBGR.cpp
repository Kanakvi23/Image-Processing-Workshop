//Scatter plot for RGB intensity

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = imread("stars.jpg",1);
	int arr[3][256];
	float arr2[3][256];
	Mat hist = Mat(800,256*3,CV_8UC3,Scalar(255,255,255));

	for(int i=0;i<3;i++)
		for(int j=0;j<256;j++)
			arr[i][j]=0;

	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			{
				arr[0][img.at<Vec3b>(i,j)[0]]++;
				arr[1][img.at<Vec3b>(i,j)[1]]++;
				arr[2][img.at<Vec3b>(i,j)[2]]++;
			}

	int max = arr[0][0];
	for(int i=0;i<3;i++)
		for(int j=0;j<256;j++)
			if(arr[i][j]>max)
				max = arr[i][j];

	if(max>800)
		for(int i=0;i<3;i++)
			for(int j=0;j<256;j++)
				arr2[i][j]=arr[i][j]*(800.0/max); 
	else
		for(int i=0;i<3;i++)
			for(int j=0;j<256;j++)
				arr2[i][j]=arr[i][j];
				
	for(int j=0;j<256;j++)
		{
			hist.at<Vec3b>(800-arr2[0][j],j*3)[1]=0;
			hist.at<Vec3b>(800-arr2[0][j],j*3+1)[1]=0;
			hist.at<Vec3b>(800-arr2[0][j],j*3)[2]=0;
			hist.at<Vec3b>(800-arr2[0][j],j*3+1)[2]=0;

			hist.at<Vec3b>(800-arr2[1][j],j*3)[0]=0;
			hist.at<Vec3b>(800-arr2[1][j],j*3+1)[0]=0;
			hist.at<Vec3b>(800-arr2[1][j],j*3)[2]=0;
			hist.at<Vec3b>(800-arr2[1][j],j*3+1)[2]=0;

			hist.at<Vec3b>(800-arr2[2][j],j*3)[1]=0;
			hist.at<Vec3b>(800-arr2[2][j],j*3+1)[1]=0;
			hist.at<Vec3b>(800-arr2[2][j],j*3)[0]=0;
			hist.at<Vec3b>(800-arr2[2][j],j*3+1)[0]=0;
		} 

	imshow("Histogram",hist);
	imshow("Image",img);
	waitKey(0);
}
