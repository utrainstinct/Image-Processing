#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("./jopening.PNG",0);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
	int a[9];
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			int z=0;
			for(int k=-1;k<=1;k++)
			{
				for(int l=-1;l<=1;l++)
				{
					a[z++]=img.at<uchar>(i+k,j+l);
				}
			}
			sort(a,a+9);
			img2.at<uchar>(i,j)=a[0];
		}
	}
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			int z=0;
			for(int k=-1;k<=1;k++)
			{
				for(int l=-1;l<=1;l++)
				{
					a[z++]=img2.at<uchar>(i+k,j+l);
				}
			}
			sort(a,a+9);
			img3.at<uchar>(i,j)=a[8];
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	namedWindow("win2",WINDOW_NORMAL);
	imshow("win2",img2);
	namedWindow("win3",WINDOW_NORMAL);
	imshow("win3",img3);
	waitKey(0);
	return 0;
}
