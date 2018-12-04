#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace cv;
using namespace std;
Mat img=imread("lenna.jpg",1);
void callback(int r,void* c)

{

Mat img2=img.clone();
int p=img.rows/2,q=img.cols/2,i,j;
for(i=0;i<img.rows;i++)
{
for(j=0;j<img.cols;j++)
{int x=j-q,y=p-i,t=sqrt(x*x+y*y);
if(r<t)
{img2.at<Vec3b>(i,j)=(0,0,0);}
else
{
img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0]*(r-t)/r;
img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1]*(r-t)/r;
img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2]*(r-t)/r;

}
}
}
imshow("win",img2);
}
int main()
{
int g=0;
namedWindow("win",WINDOW_NORMAL);
createTrackbar("radius","win",&g,img.cols,callback,NULL);

waitKey(0);
return 0;
}