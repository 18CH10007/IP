#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{

	Mat a=imread("lena.png",1);
	int r=a.rows,c=a.cols;
	Mat ch(r,c,CV_8UC1,Scalar(0,0,0));
	namedWindow("window1",WINDOW_NORMAL);
	int th=0;
	createTrackbar("slider1","window1",&th,254);
	while(1){
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			int x=a.at<uchar>(i,j);
			if(x>th)
			{
				x=255;
			}
			else
			{
				x=0;
			}
			a.at<uchar>(i,j)=x;
		}
	}
	imshow("window1",ch);
	waitKey(1);
}
	waitkey(5000);
}
