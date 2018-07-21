#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = imread("cat.jpg",1);
	Mat img_gs;
	img_gs=Mat(img.rows,img.cols,CV_8UC1);
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			img_gs.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3;
	imshow("Color to Grayscale",img_gs);
	waitKey(0);
}
