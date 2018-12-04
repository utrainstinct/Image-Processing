#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

int main()
{
	Mat img=imread("./index.jpg",0);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	int sum=0;
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			sum=0;
			for(int k=-1;k<=1;k++)
			{
				for(int l=-1;l<=1;l++)
				{
					sum=sum+img.at<uchar>(i+k,j+l);
				}
			}
			
			img2.at<uchar>(i,j)=sum/9;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img2);
	waitKey(0);
	return 0;
}
