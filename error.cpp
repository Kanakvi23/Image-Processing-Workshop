#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = imread("cat.jpg",1);
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
		{
			img.at<Vec3b>(i,j)[0]=1.2*img.at<Vec3b>(i,j)[0];
			img.at<Vec3b>(i,j)[1]=1.2*img.at<Vec3b>(i,j)[1];
			img.at<Vec3b>(i,j)[2]=1.2*img.at<Vec3b>(i,j)[2];
		}
	imshow("Cat",img);
	waitKey(0);
}