#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stack>

using namespace cv;
using namespace std;

Mat src,match;
//int sat,val,hue,err;

/*void threshCallback(int,void*)
{
	ball= ball-ball;
	
	for(int i=0;i<src.rows;i++)
		for(int j=0;j<src.cols;j++)
		{
			if(src.at<Vec3b>(i,j)[0]>=hue-err && src.at<Vec3b>(i,j)[0]<=hue+err)
			{
				if(src.at<Vec3b>(i,j)[1]>=sat-err && src.at<Vec3b>(i,j)[1]<=sat+err)
				{
					if(src.at<Vec3b>(i,j)[2]>=val-err && src.at<Vec3b>(i,j)[2]<=val+err)
					{
						ball.at<Vec3b>(i,j)[0]=src.at<Vec3b>(i,j)[0];
						ball.at<Vec3b>(i,j)[1]=src.at<Vec3b>(i,j)[1];
						ball.at<Vec3b>(i,j)[2]=src.at<Vec3b>(i,j)[2];
					}
				}
			}
		}
	imshow("Dsiplay",ball);
	//imshow("Dsiplay2",src);
}*/

/*void CallbackFunc(int event,int y,int x, int flags, void* userdata)
{
	if(event==EVENT_LBUTTONDOWN)
	{
		int h=src.at<Vec3b>(x,y)[0];
		int s=src.at<Vec3b>(x,y)[1];
		int v=src.at<Vec3b>(x,y)[2];
		cout<<h<<"  "<<s<<"  "<<v<<endl;

		cout<<x<<" "<<y<<endl;
	}	
}*/	

int main()
{
	VideoCapture cap("new.mp4");
	int gr=0,gl=0;
	int flagl=0,flagr=0,detected=0;

	while(1)
	{
		cap>>match;
		cvtColor(match,src,CV_BGR2HSV);
		int detected=0;
		//ball = Mat(src.rows,src.cols,CV_8UC3,Scalar(0,0,0));
		//cvtColor(ball,ball,CV_BGR2HSV);
		//namedWindow("Display",WINDOW_AUTOSIZE);
		/*createTrackbar("Hue","Display",&hue,255,threshCallback);
		createTrackbar("Sat","Display",&val,255,threshCallback);
		createTrackbar("Val","Display",&sat,255,threshCallback);
		createTrackbar("Err","Display",&err,255,threshCallback);*/
		//imshow("Display",src);
		//setMouseCallback("Display",CallbackFunc,NULL);
		
		for(int i=200;i<600;i++)
			for(int j=0;j<70;j++)
			{	
				if(src.at<Vec3b>(i,j)[0]>=8-45 && src.at<Vec3b>(i,j)[0]<=8+45 && src.at<Vec3b>(i,j)[1]>=234-45 && src.at<Vec3b>(i,j)[1]<=234+45 && src.at<Vec3b>(i,j)[2]>=224-45 && src.at<Vec3b>(i,j)[2]<=224+45)
						{
							detected=1;
							//cout<<"detected"<<endl;
						}
			}
				
				if(detected==1)
				{	
					if(flagl==0)
						{
							gl++;
							cout<<"goal icremented"<<endl;
							flagl=1;
						}
					else
						{
							//cout<<"continued"<<endl;
							continue;
						}
				}
				else
					{
						//cout<<"not detected"<<endl;
						flagl=0;
					}

		for(int i=290;i<550;i++)
			for(int j=1056;j<1070;j++)
			{	
				if(src.at<Vec3b>(i,j)[0]>=8-20 && src.at<Vec3b>(i,j)[0]<=8+20 && src.at<Vec3b>(i,j)[1]>=234-20 && src.at<Vec3b>(i,j)[1]<=234+20 && src.at<Vec3b>(i,j)[2]>=224-20 && src.at<Vec3b>(i,j)[2]<=224+20)
				{
					if(flagr==0)
						{
							gr++;
							flagr=1;
						}
					else
						continue;
				}
				else
					flagr=0;
			}
		cout<<gl<<"   "<<gr<<endl;
		imshow("Match",match);
		waitKey(70);
	}
}