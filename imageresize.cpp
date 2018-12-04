#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{

    

    Mat img = imread("./lenna.jpg", 1);
    Mat img2(img.rows*2,img.cols*2,CV_8UC3,(0,0,0));
    for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
			{
				img2.at<Vec3b>(2*i,2*j)=img.at<Vec3b>(i,j);
				img2.at<Vec3b>(2*i+1,2*j)=img.at<Vec3b>(i,j);
				img2.at<Vec3b>(2*i,2*j+1)=img.at<Vec3b>(i,j);
				img2.at<Vec3b>(2*i+1,2*j+1)=img.at<Vec3b>(i,j);
			}
	}
    namedWindow("lenna",WINDOW_AUTOSIZE);
    imshow("lenna",img);
    namedWindow("lenna2",WINDOW_AUTOSIZE);
    imshow("lenna2",img2);
    waitKey(0);
    return 0;
}
