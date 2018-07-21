// Blob Detection using DFS
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stack>

using namespace cv;
using namespace std;

Mat img;


struct point
{
    int x;
    int y;
};


void dfs(struct point p, int **vis)
{
    stack<struct point> s;
    struct point temp,temp2;

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

}


int main()
{
    img=imread("binary.png",2);
    struct point p;
    
    int **vis=new int*[img.rows];
    for(int i=0;i<img.rows;i++)
        vis[i]=new int[img.cols];
    
    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
            vis[i][j]=0;
    int count =0;
    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
        {    
            if(vis[i][j]==0 && img.at<uchar>(i,j)==255)
                {    vis[i][j]=1;
                    p.x=i;
                    p.y=j;        
                    dfs(p,vis);
                    count++;
                }
        }
    
    Mat img_dfs = Mat(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));

    for(int i=0;i<img.rows;i++)
        for(int j=0;j<img.cols;j++)
            if(vis[i][j]==1)
                img_dfs.at<Vec3b>(i,j)[0]=255;
    
    imshow("Blob Detected",img_dfs);
    imshow("Original",img);
    waitKey(0);
}
