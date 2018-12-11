#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
	{
		int f,k;
		Mat img=imread("darkimage.PNG",0);
		namedWindow("window1",WINDOW_NORMAL);

		Mat a(500,256,CV_8UC1,Scalar(0));
		namedWindow("Histogram",WINDOW_NORMAL);

		for (int i = 0; i < img.rows; ++i)
			{
				for (int j = 0; j < img.cols; ++j)
					{
						int y;
						int p=img.at<uchar>(i,j);
						//p is intensity of pixel. Therefore, f should be no. of pixels of 'that' intensity.
						f[k]++;
						a.at<uchar>(p,f)=y;
					}
			}
			imshow("window1",img);
			imshow("Histogram",a);
			waitKey(0);
	}	