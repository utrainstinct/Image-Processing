#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace cv;
using namespace std;
void callback(int t,void* s)
{
	Mat img  = imread("rubik.jpg",0);
	Mat img2 = img.clone();
	int i,j,k,l,z=0;
	int a[9];
	for(i=1;i<img.rows-1;i++)
	{
		for(j=1;j<img.cols-1;j++)
		{
			z=0;
			for(k=-1;k<=1;k++)
			{
				for(l=-1;l<=1;l++)
				{
					a[z++]=img.at<uchar>(i+k,j+l);
				}
			}
			int x=((a[0]+a[3]+a[6])*(-1) + (a[2]+a[5]+a[8]))/6;
			int y=((a[0]+a[1]+a[2])*(-1) + (a[6]+a[7]+a[8]))/6;
			if(sqrt(x*x+y*y)<t)
			{
				img2.at<uchar>(i,j)=0;
			}
		}
	}
	Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=1;i<img.rows-1;i++)
	{
		for(j=1;j<img.cols-1;j++)
		{
			z=0;
			for(k=-1;k<=1;k++)
			{
				for(l=-1;l<=1;l++)
				{
					a[z++]=img2.at<uchar>(i+k,j+l);
				}
			}
			sort(a,a+9);
			img3.at<uchar>(i,j)=a[8];
		}
	}
	Mat img4(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(i=1;i<img.rows-1;i++)
	{
		for(j=1;j<img.cols-1;j++)
		{
			z=0;
			for(k=-1;k<=1;k++)
			{
				for(l=-1;l<=1;l++)
				{
					a[z++]=img3.at<uchar>(i+k,j+l);
				}
			}
			sort(a,a+9);
			img4.at<uchar>(i,j)=a[0];
		}
	}
	imshow("win",img4);
}
int main()
{
	int th=0;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("threshold","win",&th,200,callback,NULL);
	waitKey(0);
	return 0;
}