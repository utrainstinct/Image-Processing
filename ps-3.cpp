#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace cv;
using namespace std;
double PI=3.1416;

int main()
{
	Mat img1=imread("66.jpg",0);
	Mat img2=imread("88.jpg",0);
	Mat img3=imread("l31.jpg",0);
	double tan,theta,thetad;
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			if(img1.at<uchar>(i,j)>100)
				img1.at<uchar>(i,j)=255;
			else
				img1.at<uchar>(i,j)=0;
		}
	}
	for(int i=0;i<img2.rows;i++)
	{
		for(int j=0;j<img2.cols;j++)
		{
			if(img2.at<uchar>(i,j)>30)
				img2.at<uchar>(i,j)=255;
			else
				img2.at<uchar>(i,j)=0;
		}
	}
	for(int i=0;i<img3.rows;i++)
	{
		for(int j=0;j<img3.cols;j++)
		{
			if(img3.at<uchar>(i,j)>100)
				img3.at<uchar>(i,j)=255;
			else
				img3.at<uchar>(i,j)=0;
		}
	}
	dilate(img1,img1,Mat());
	erode(img1,img1,Mat());
	dilate(img2,img2,Mat());
	erode(img2,img2,Mat());
	dilate(img3,img3,Mat());
	erode(img3,img3,Mat());
	vector<vector<Point>> contours1;
	vector<vector<Point>> contours2;
	vector<vector<Point>> contours3;
	vector<Vec4i> hierarchy;
	findContours(img1,contours1,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
		Mat drawing1=Mat::zeros(img1.size(),CV_8UC3);
   		for( int i = 0; i< contours1.size(); i++ )
	    {
	    	Scalar color( 255, 255, 255 );
	    	drawContours(drawing1, contours1, i, color, 2, 8, hierarchy, 0, Point() );
	    }
		imshow("win1",drawing1);
		findContours(img2,contours2,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
		Mat drawing2=Mat::zeros(img2.size(),CV_8UC3);
   		for( int i = 0; i< contours2.size(); i++ )
	    {
	    	Scalar color( 255, 255, 255 );
	    	drawContours(drawing2, contours2, i, color, 2, 8, hierarchy, 0, Point() );
	    }
		imshow("win2",drawing2);
		findContours(img3,contours3,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
		Mat drawing3=Mat::zeros(img3.size(),CV_8UC3);
   		for( int i = 0; i< contours3.size(); i++ )
	    {
	    	Scalar color( 255, 255, 255 );
	    	drawContours(drawing3, contours3, i, color, 2, 8, hierarchy, 0, Point() );
	    }
		imshow("win3",drawing3);
		Mat grey1,binary1;
		cvtColor( drawing1, grey1, COLOR_BGR2GRAY );
		threshold( grey1, binary1, 50,255,THRESH_BINARY );
		Moments m1 = moments(binary1,true);
		int cx1=m1.m10/m1.m00;
		int cy1=m1.m01/m1.m00;
		tan=(double)2*(binary1.cols/2-cx1)/binary1.rows;
		theta=atan(tan);
		thetad=theta*180/PI;
		if(binary1.cols/2-cx1<0)
			cout<<"right by "<<-thetad<<endl;
		else if(binary1.cols/2-cx1>0)
			cout<<"left by "<<thetad<<endl;
		else
			cout<<"don't turn"<<endl;
		Mat grey2,binary2;
		cvtColor( drawing2, grey2, COLOR_BGR2GRAY );
		threshold( grey2, binary2, 50,255,THRESH_BINARY );
		Moments m2 = moments(binary2,true);
		int cx2=m2.m10/m2.m00;
		int cy2=m2.m01/m2.m00;
		tan=(double)2*(binary2.cols/2-cx2)/binary2.rows;
		theta=atan(tan);
		thetad=theta*180/PI;
		if(binary2.cols/2-cx2<0)
			cout<<"right by "<<-thetad<<endl;
		else if(binary2.cols/2-cx2>0)
			cout<<"left by "<<thetad<<endl;
		else
			cout<<"don't turn"<<endl;
		Mat grey3,binary3;
		cvtColor( drawing3, grey3, COLOR_BGR2GRAY );
		threshold( grey3, binary3, 50,255,THRESH_BINARY );
		Moments m3 = moments(binary3,true);
		int cx3=m3.m10/m3.m00;
		int cy3=m3.m01/m3.m00;
		tan=(double)2*(binary3.cols/2-cx3)/binary3.rows;
		theta=atan(tan);
		thetad=theta*180/PI;
		if(binary3.cols/2-cx3<0)
			cout<<"right by "<<-thetad<<endl;
		else if(binary3.cols/2-cx3>0)
			cout<<"left by "<<thetad<<endl;
		else
			cout<<"don't turn"<<endl;
	waitKey(0);
	return 0;

}