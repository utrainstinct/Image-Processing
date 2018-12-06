#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture vid(0);
	Mat frame;
	Mat segment;
	Mat canny;
	while(1)
	{
		vid>>frame;
		vid>>segment;
		for(int i=0;i<frame.rows;i++)
		{
			for(int j=0;j<frame.cols;j++)
			{
				if(frame.at<Vec3b>(i,j)[0]<0 || frame.at<Vec3b>(i,j)[0]>255)
					segment.at<Vec3b>(i,j)={0,0,0};
				if(frame.at<Vec3b>(i,j)[1]<0 || frame.at<Vec3b>(i,j)[1]>128)
					segment.at<Vec3b>(i,j)={0,0,0};
				if(frame.at<Vec3b>(i,j)[2]<205 || frame.at<Vec3b>(i,j)[2]>255)
					segment.at<Vec3b>(i,j)={0,0,0};
			}
		}
		blur(segment,segment,Size(3,3));
		vector<vector<Point>>contours;
  		vector<Vec4i>hierarchy;
  		Canny(segment,canny,160,480,3);
  		findContours(canny,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
  		Mat contour=Mat::zeros(canny.size(),CV_8UC3);
   		for( int i = 0; i< contours.size(); i++ )
	    {
	    	Scalar color( 255, 255, 255 );
	    	drawContours(contour, contours, i, color, 2, 8, hierarchy, 0, Point() );
	    }
		imshow("win",contour);
		double area=0.0;
		for (int i = 0;  i < contours.size();  i++)
		{	
			if(area < contourArea(contours[i]))
			{
				area=contourArea(contours[i]);			}
		}
		cout<<"Area is "<<area;
		int x;
		if(area<1000)
			x=127;
		else if(area>70000)
			x=-127;
		else if(area>50000 && area<70000)
			x=0;
		else
			x=127-area*127/50000;
		cout<<" speed is "<<x;
		Mat grey,binary;
		cvtColor( contour, grey, COLOR_BGR2GRAY );
		threshold( grey, binary, 50,255,THRESH_BINARY );
		Moments m = moments(binary,true);
		int cx=m.m10/m.m00;
		int cy=m.m01/m.m00;
		int y=0;
		if(area != 0)
		{
		if(frame.cols/2-cx<-50)
			y=127;
		else if(frame.cols/2-cx>50)
			y=-127;
		else
			y=0;
		}
		cout<<" angular speed is "<<y<<endl;
		waitKey(100);
	}
	return 0;

}