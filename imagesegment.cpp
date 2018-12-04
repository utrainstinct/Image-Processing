#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("./a.png",1);
int b_low =0, b_high =255, red_high =255, red_low =0, g_low =0, g_high=255;

void callback1(int t, void* s)
    {
      Mat cpy=img.clone();
  int i,j;
   for(i=0;i<img.rows;i++)
    {
    for(j=0;j<img.cols;j++)
      {
	if(img.at<Vec3b>(i,j)[0]>b_high ||  img.at<Vec3b>(i,j)[0]<b_low)
	  cpy.at<Vec3b>(i,j) = {0,0,0};
	if(img.at<Vec3b>(i,j)[1]>g_high || img.at<Vec3b>(i,j)[1]<g_low)
	  cpy.at<Vec3b>(i,j) = {0,0,0};
	if(img.at<Vec3b>(i,j)[2]>red_high || img.at<Vec3b>(i,j)[2]<red_low)
	  cpy.at<Vec3b>(i,j) = {0,0,0};
	

    }
    }
    imshow("fruit",cpy);
 
}


  int main(){
    int g=127;
    namedWindow("fruit",WINDOW_NORMAL);
    createTrackbar("Bluelow","fruit",&b_low,255,callback1,NULL);
     createTrackbar("Bluehigh","fruit",&b_high,255,callback1,NULL);
    createTrackbar("Greenlow","fruit",&g_low,255,callback1,NULL);
     createTrackbar("Greenhigh","fruit",&g_high,255,callback1,NULL);
    createTrackbar("Redlow","fruit",&red_low,255,callback1,NULL);
     createTrackbar("Redhigh","fruit",&red_high,255,callback1,NULL);
    waitKey(0);
    return 0;

  }
