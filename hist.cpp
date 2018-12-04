#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

int main()
{
Mat img=imread("lightimage.PNG",0);
int pixelarr[256],t=0;
for(t=0;t<256;t++){
pixelarr[t]=0;
}
int i,j;
for(i=0;i<img.rows;i++)
	{
	for(j=0;j<img.cols;j++)
	{	
			pixelarr[img.at<uchar>(i,j)]++;

	}
	}
int max=pixelarr[0];
	for(t=0;t<256;t++)
	{
	if(pixelarr[t]>max)
	max=pixelarr[t];
}

Mat img2(max,256,CV_8UC1,Scalar(0));
for(i=0;i<256;i=i+1)
{
for(j=0;j<pixelarr[i];j++)
{
img2.at<uchar>(max-1-j,i)=255;
}
}

namedWindow("win",WINDOW_NORMAL);
imshow("win",img2);
waitKey(0);
return 0;
}

