//To remove noise without updating original image (taking mean)


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = imread("lena_n.png",2);
	Mat img2 = Mat(img.rows,img.cols,CV_8UC1);
	float ker[3][3];
	int mean;

	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			img2.at<uchar>(i,j)=img.at<uchar>(i,j);

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ker[i][j]=1.0/9;

	for(int i=1;i<img.rows-1;i++)
		{
			for(int j=1;j<img.cols-1;j++)
			{	mean=0;
				int cntr=1;	
				int cntc=1;
				for(int k=0;k<3;k++)
				{	
					for(int l=0;l<3;l++)
					{	
						mean = mean + (img.at<uchar>(i-cntr,j-cntc)*ker[k][l]);
						cntc--;
					} 
					cntr--;
				}
			img2.at<uchar>(i,j)=mean;
			}
		}
	imshow("Noise Removed",img2);
	imshow("Original",img);
	waitKey(0);
}