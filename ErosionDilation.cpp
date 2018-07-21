#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;


Mat erosion(Mat img)
{
	Mat imge = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			imge.at<uchar>(i,j)=img.at<uchar>(i,j);

	int ker[3][3];

	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			int cntr=1;
			for(int k=0;k<3;k++)
			{	
				int cntc=1;
				for(int l=0;l<3;l++)
				{
					ker[k][l]=img.at<uchar>(i-cntr,j-cntc);
					cntc--;
				}
				cntr--;
			}
		int min=255;
		for(int k=0;k<3;k++)
			for(int l=0;l<3;l++)
				if(ker[k][l]<min)
					min = ker[k][l];

		if(min==0)
			imge.at<uchar>(i,j)=0;
		}
	}
	
	return(imge);
}

Mat dilation(Mat imge)
{
	Mat imgd = Mat(imge.rows,imge.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<imge.rows;i++)
		for(int j=0;j<imge.cols;j++)
			imgd.at<uchar>(i,j)=imge.at<uchar>(i,j);

	int ker[3][3];

	for(int i=1;i<imge.rows-1;i++)
	{
		for(int j=1;j<imge.cols-1;j++)
		{
			int cntr=1;
			for(int k=0;k<3;k++)
			{	
				int cntc=1;
				for(int l=0;l<3;l++)
				{
					ker[k][l]=imge.at<uchar>(i-cntr,j-cntc);
					cntc--;
				}
				cntr--;
			}
		int max=0;
		for(int k=0;k<3;k++)
			for(int l=0;l<3;l++)
				if(ker[k][l]>max)
					max = ker[k][l];

		if(max==255)
			imgd.at<uchar>(i,j)=255;
		}
	}
	return(imgd);	
}


int main(int argc, char **argv)
{
	Mat img;
	img = imread(argv[1],2);
	Mat imge = erosion(img);
	Mat imgd = dilation(imge);
	imshow("Original",img);
	imshow("Erosion",imge);
	imshow("Dilation",imgd);
	waitKey(0);	
} 
