#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("./veg.jpg",0);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
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
			img2.at<uchar>(i,j)=(a[0]+a[2]+a[6]+a[8])/16+(a[1]+a[3]+a[5]+a[7])/8+a[4]/4;


		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img2);
	namedWindow("win2",WINDOW_NORMAL);
	imshow("win2",img);
	waitKey(0);
	return 0;
}
