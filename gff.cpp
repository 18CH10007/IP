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
          
     for(i=0;i<(img.rows/2);i++){
       for(j=0;j<(img.cols/2);j++){
     	int I1=img.at<Vec3b>(2*i,2*j);
     	int I2=img.at<Vec3b>(2*i+1,2*j+1);
     	int I3=img.at<Vec3b>(2*i+1,2*j);
        int I4=img.at<Vec3b>(2*i,2*j+1);
     	int ab=(I1+I2+I3+I4)/4;
     	a.at<Vec3b>(i,j)=ab;
       }
     }
     imshow("window1",img);
     imshow("IMG",a);
     waitKey(0);
     }
