#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace cv;
using namespace std;
double PI=3.1416;
void callback(int t,void* s)
{
	Mat img=imread("lenna.jpg",1);
Mat img2(img.rows*2,img.cols*2,CV_8UC3,Scalar(0,0,0));
Mat img3=img2.clone();
int i,j,p=img2.rows/2,q=img2.cols/2;
for(i=img.rows/2;i<img.rows/2+img.rows;i++)
{
	for(j=img.cols/2;j<img.cols/2+img.cols;j++)
	{
		img2.at<Vec3b>(i,j)=img.at<Vec3b>(i-img.rows/2,j-img.cols/2);
	}
}
for(i=img.rows/2;i<img.rows/2+img.rows;i++)
{
	for(j=img.cols/2;j<img.cols/2+img.cols;j++)
	{
		int x=j-q,y=p-i;
		int c=cos(t*PI/180)*x-sin(t*PI/180)*y,b=sin(t*PI/180)*x+cos(t*PI/180)*y;
		img3.at<Vec3b>(p-b,q+c)=img2.at<Vec3b>(i,j);

		}
	}
	imshow("win2",img3);
}
int main()
{
	int angle=0;
	namedWindow("win2",WINDOW_NORMAL);
	createTrackbar("angle","win2",&angle,360,callback,NULL);
	waitKey(0);
	return 0;
}
