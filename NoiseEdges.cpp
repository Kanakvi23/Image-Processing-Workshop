#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
	Mat img;
	img = imread(argv[1],2);
	float ker[3][3];
	float num,sum;

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(((i+j)%2)==0)		
				ker[i][j]=1.0;
			else
				ker[i][j]=2.0;

	ker[1][1]=4.0;

	for(int i=0;i<img.rows;i++)
		{
			for(int j=0;j<img.cols;j++)
			{	sum=0;
				num=0;
				int cntr=1;	
				int cntc=1;
				for(int k=0;k<3;k++)
				{	
					for(int l=0;l<3;l++)
					{	
						if(i-cntr<0 || i-cntr>img.rows || j-cntc<0 || j-cntc>img.cols)
							continue;
						sum = sum + (img.at<uchar>(i-cntr,j-cntc)*ker[k][l]);
						num = num + ker[k][l]; 
						cntc--;
					} 
					cntr--;
				}
			img.at<uchar>(i,j) = int(sum/num);
			}
		}
	imshow("Noise Removed",img);
	waitKey(0);
}