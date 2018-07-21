//To remove noise by uodating the original image 5 times


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = imread("lena_n.png",2);
	float ker[3][3];
	int mean;
	int loop=5;

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ker[i][j]=1.0/9;

	while(loop>0){	
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
			img.at<uchar>(i,j)=mean;
			}
		}
	loop--;
	}
	imshow("Noise Removed",img);
	waitKey(0);
}