#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(int,char**)
{
	Mat abc,img;
	VideoCapture cap(0);
	namedWindow("IMG");
	namedWindow("Final");
	if(!cap.isOpened())
		return -1;
	while(1)
	{
		Mat img;
		cap>>img;
		Canny(img,abc,50,100,5);
		imshow("Final",img);
		imshow("IMG",abc);
		waitKey(1);
	}
}	