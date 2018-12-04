#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#include <cmath>

using namespace cv;
using namespace std;
double PI=3.1416;

int main()
	{
		int i,j,ang;
		Mat img=imread("ab.png",0);
		int r=sqrt(img.rows*img.rows+img.cols*img.cols);
		int a[r][180];
		for(i=0;i<r;i++)
				{
					for(j=0;j<180;j++)
							{
								a[i][j]=0;
							}
				}
		for(i=0;i<img.rows;i++)
				{
					for(j=0;j<img.rows;j++)
						{
							for(ang=0;ang<180;ang += 1)
									{
										if(img.at<uchar>(i,j)==255)	
											{
												int k=abs(j*cos(ang*PI/180)-i*sin(ang*PI/180));
												a[k][ang] += 5;
											}
									}
						}
				}
		Mat img2(r,180,CV_8UC1,Scalar(0));
		for(i=0;i<r;i++)
			{
				for(j=0;j<180;j++)
						{
							img2.at<uchar>(i,j)=a[i][j];
						}
			}
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",img2);
		waitKey(0);
		return 0;
	}
