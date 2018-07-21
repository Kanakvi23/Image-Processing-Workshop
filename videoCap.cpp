
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;



int main()
{	
	VideoCapture cap(0);
	Mat src;

	while(1)
	{
		cap>>src;
		imshow("hi",src);
		waitKey(10);
	}

}