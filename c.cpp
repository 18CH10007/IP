#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	int i,j;

     Mat img=imread("fruits.png",1);
     namedWindow("IMG",WINDOW_NORMAL);

     Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));

     namedWindow("window1",WINDOW_NORMAL);
          
     for(i=0;i<img.rows;i++){
       for(j=0;j<img.cols;j++){
     	int Ib=img.at<Vec3b>(i,j)[0];
     	int Ig=img.at<Vec3b>(i,j)[1];
     	int Ir=img.at<Vec3b>(i,j)[2];
     	int ab=(0.114*Ib+0.587*Ig+0.299*Ir);
     	a.at<uchar>(i,j)=ab;
       }
     }
     imshow("window1",img);
     imshow("IMG",a);
     waitKey(0);
     }
