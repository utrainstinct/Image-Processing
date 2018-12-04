#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;


Mat img = imread("bwdfs.png",0);
int done = 0;

int isValid(int i, int j)
{
	if(i>=0 && j>=0 && i<img.rows && j<img.cols)
		return 1;
	else 
		return 0;
}
Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));


int dfs(int i,int j)
{
	if(done == 1) return 1;
	if(i ==img.rows-1 && j ==img.cols-1) {
		done = 1;
		return done;
	}
	if(isValid(i,j)==1 && i < img.rows-1 && j < img.cols-1 )
	{

		for(int a=1;a>-2;a--)
		{
			for(int b=1;b>-2;b--)
			{
				if(done==0)
				if(img.at<uchar>(i+a,j+b)==255 && img2.at<uchar>(i+a,j+b)==0)
				{
					img2.at<uchar>(i+a,j+b)=255;
					img.at<uchar>(i+a,j+b)=0;
					imshow("win",img);
					imshow("win2",img2);
					waitKey(1);
					done=dfs(i+a,j+b);
				}
			}
		}
		return done;
	}		

	
}
int main()
{
	namedWindow("win",WINDOW_NORMAL);
	namedWindow("win2",WINDOW_NORMAL);

	int k=0,l=0;
	for(k=0;k<img.rows;k++)
	{
		for(l=0;l<img.cols;l++)
		{	
			if(k < img.rows-1 && l < img.cols-1 )
			{
			if(img2.at<uchar>(k,l)==0 && isValid(k,l)==1)
			{
				img2.at<uchar>(k,l)=255;
				if(img.at<uchar>(k,l)==255)
				{	
					img.at<uchar>(k,l)=0;

					int temp=dfs(k,l);
				}
			}
		}

		}
	}
	return 0;
}	