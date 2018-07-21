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


int main()
{
	
	Mat img = imread("dfs_path.png",2);

	stack<point> s;
	point beg = {1,1};
	point end = {img.rows-1,img.cols-1};
	point temp;

	s.push(beg);
	point p=beg;

	int vis[1000][1000];													//Every point not visited right now	
	for(int i=0;i<img.rows;i++)
		for(int j=0;j<img.cols;j++)
			vis[i][j]=0;


	while(p.x!=end.x && p.y!=end.y)
	{	
		vis[p.x][p.y]=1;													//Point p marked visited
		int flag=1;															//Check if all the points around p are visited. If visited already, pop.
		for(int k=-1;k<2;k++)
			for(int j=-1;j<2;j++)
			{
				if(p.x+k<0 || p.x+k>img.rows || p.y+j<0 || p.y+j>img.cols)
					continue;
				if(vis[p.x+k][p.y+j]==0)
					flag=0;
			}
		if(flag==1)
			s.pop();

		for(int k=-1;k<2;k++)
			for(int j=-1;j<2;j++)
			{	
				if(p.x+k<0 || p.x+k>img.rows || p.y+j<0 || p.y+j>img.cols)
					continue;
				if(p.x+k == end.x && p.y+j == end.y)
				{	
					temp.x=p.x+k;
					temp.y=p.y+j;
					s.push(temp)
					break;
				}
				if(img.at<uchar>(p.x+k,p.y+j)==255 && vis[p.x+k][p.y+j]==0)
				{
					push(p);
					p=s.top();
				}

			}
	}

	

}