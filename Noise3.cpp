//remove noise in the same image using median
//don't use edge detection for median

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <algorithm>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	img = imread("veg.jpg",2);

	float ker[3][3];
	int mean;
	int arr[9];

	for(int i=0;i<img.rows;i++)
		{
			for(int j=0;j<img.cols;j++)
			{	
				int cntr=1;	
				int cntc=1;
				int ind=0;
				for(int k=0;k<3;k++)
				{	
					for(int l=0;l<3;l++)
					{
						if (i - cntr < 0 || i - cntr >= img.rows || j - cntc < 0 || j - cntc >= img.cols)
							continue;	
						arr[ind++] = img.at<uchar>(i-cntr,j-cntc);
						cntc--;
					} 
					cntr--;
				}
			sort(arr,arr+ind);
			img.at<uchar>(i,j)=arr[ind/2];
			}
		}
	imshow("Noise Removed",img);
	waitKey(0);
}