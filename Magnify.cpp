#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

using namespace std;

int main()
{
	Mat img;
	img = imread("dog.jpeg",1);
	Mat img2;
	img2 = Mat(2*img.rows,2*img.cols,CV_8UC3,Scalar(0,0,0));

	for(int i=0;i<img2.rows;i++)
		for(int j=0;j<img2.cols;j++)
		{
			img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i/2,j/2)[0];
			img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i/2,j/2)[1];
			img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i/2,j/2)[2];
		}
	imshow("Magnified Image",img2);
	waitKey(0);
}