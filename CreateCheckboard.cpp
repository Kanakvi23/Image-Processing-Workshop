#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = Mat(512,512,CV_8UC1);

	for(int i=0; i<512;i++){
		for(int j=0;j<512;j++)
		{	if(((i/64)+(j/64))%2==1)
				img.at<uchar>(i,j)=255;
		}
	}
imshow("Checkerboard",img);
waitKey(0);
}