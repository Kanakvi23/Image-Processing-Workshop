#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stack>

using namespace cv;
using namespace std;

typedef struct 
{
	int x;
	int y;
}point;

Mat img; 
int **vis;
	point **parent;

void dfs(point beg, point end, int **vis, point **parent)
{
	stack<point> s;
	point temp,temp2;

	s.push(beg);
	

	while(!s.empty())
	{	
		temp2=s.top();
		s.pop();
		for(int i=-1;i<2;i++)
			for(int j=-1;j<2;j++)
			{	if(temp2.x+i<0 || temp2.x+i>=img.rows || temp2.y+j<0 || temp2.y+j>=img.cols)
					continue;
				if(img.at<uchar>(temp2.x+i,temp2.y+j)==255 && vis[temp2.x+i][temp2.y+j]==0)
				{
					temp.x=temp2.x+i;
					temp.y=temp2.y+j;
					vis[temp.x][temp.y]=1;
					parent[temp.x][temp.y].x=temp2.x;
					parent[temp.x][temp.y].y=temp2.y;
					s.push(temp);
				}
			}
	}

	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
		{
			cout<<parent[i][j].x<<","<<parent[i][j].y<<endl;
		}
	

	
}

int main()
{
	img = imread("dfs_path.jpg",2);
	point beg = {0,0};
	point end = {img.rows-1,img.cols-1};

	vis = new int*[img.rows];
	parent = new point*[img.rows];
	
	for(int i=0;i<img.rows;i++)
		vis[i]=new int[img.cols];
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			vis[i][j]=0;

	for(int i=0;i<img.rows;i++)
		parent[i] = new point[img.cols];
	/*for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
		{
			parent[i][j].x=img.rows;
			parent[i][j].y=img.cols;
		}
		*/

	parent[0][0].x=0;
	parent[0][0].y=0;

	dfs(beg,end,vis,parent);


	Mat path = Mat(img.rows,img.cols,CV_8UC1,Scalar(0));
	int k,l;
	int i,j;
	i=end.x;
	j=end.y;
	while(k!=0 && l!=0)
	{
		//for(int i=-1;i<2;i++)
			//for(int j=-1;j<2;j++)
			//{
				//if(end.x+i<0 || end.x+i>=img.rows || end.y+j<0 || end.y+j>=img.cols)
				//	continue;
				//path.at<uchar>(end.x,end.y)=255;
				//img.at<uchar>(end.x,end.y)=0;
			//}
			
		path.at<uchar>(i,j)=255;
		img.at<uchar>(i,j)=0;
		k=parent[i][j].x;
		l=parent[i][j].y;
		i=k;
		j=l;

	}

imshow("Path",path);
imshow("Path2",img);

waitKey(0);
}
