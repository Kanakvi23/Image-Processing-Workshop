
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img, img_gray;
Mat dst, edges;
int threshld;


void canny(int, void*)
{
	//edges = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));
	dst = Mat(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	blur(img_gray,edges,Size(3,3));
	Canny(edges,edges,threshld,threshld*3,3);
	img.copyTo(dst,edges);
	imshow("Edges",edges);
	imshow("Canny2",dst);
	waitKey(5);
}


int main(int argc, char **argv)
{
	img = imread(argv[1],1);
	
	img_gray = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));

	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			img_gray.at<uchar>(i,j)=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3;

	namedWindow("Canny2",WINDOW_AUTOSIZE);
	createTrackbar("Threshold","Canny2",&threshld,100,canny);
	canny(0,0);
	waitKey(0);
}
