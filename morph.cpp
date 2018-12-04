#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img = imread("./lenna.jpg",1);
Mat imgm = imread("./grey.jpg",1);
int percent=0;

void callback1(int t, void* s)
    {
      Mat cpy=img.clone();
  int i,j;
   for(i=0;i<img.rows;i++)
    {
    for(j=0;j<img.cols;j++)
        {
		cpy.at<Vec3b>(i,j)[0]=(imgm.at<Vec3b>(i,j)[0]*percent + img.at<Vec3b>(i,j)[0]*(100-percent))/100;
		cpy.at<Vec3b>(i,j)[1]=(imgm.at<Vec3b>(i,j)[1]*percent + img.at<Vec3b>(i,j)[1]*(100-percent))/100;
		cpy.at<Vec3b>(i,j)[2]=(imgm.at<Vec3b>(i,j)[2]*percent + img.at<Vec3b>(i,j)[2]*(100-percent))/100;
	}
    }
    imshow("morph",cpy);
 
}


  int main(){
    namedWindow("morph",WINDOW_NORMAL);
    createTrackbar("Morph Percent","morph",&percent,100,callback1,NULL);
    waitKey(0);
    return 0;

  }
