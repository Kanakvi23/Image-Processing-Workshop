// Problem Statement 1: To implement the Fill Bucket tool of Paint 
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

Mat img=imread("shapes.jpg",2) ; 



void dfs(point p)
{
    stack<point> s;
    point temp,temp2;
    
    int i,j;

    int **vis=new int*[img.rows];
    for(int i=0;i<img.rows;i++)
        vis[i]=new int[img.cols];
    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
            vis[i][j]=0;

    s.push(p);

    while(!s.empty())
    {    
        temp2=s.top();
        s.pop();
        for(int i=-1;i<2;i++)
            for(int j=-1;j<2;j++)
            {    if(temp2.x+i<0 || temp2.x+i>=img.rows || temp2.y+j<0 || temp2.y+j>=img.cols)
                    continue;
                if(img.at<uchar>(temp2.x+i,temp2.y+j)==255 && vis[temp2.x+i][temp2.y+j]==0)
                {
                    temp.x=temp2.x+i;
                    temp.y=temp2.y+j;
                    vis[temp.x][temp.y]=1;
                    s.push(temp);
                }
            }
    }

    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
            if(vis[i][j]==1)
                img.at<uchar>(i,j)=100;

    imshow("Display",img);
}


void CallbackFunc(int event,int y,int x, int flags, void* userdata)
{
    
    if(event==EVENT_LBUTTONDOWN)
    {
        point p;
        p.x=x;
        p.y=y;
        dfs(p);
    }
}


int main()
{
    
    point p;

    imshow("Display",img);
    setMouseCallback("Display",CallbackFunc,NULL);
    waitKey(0);
}
