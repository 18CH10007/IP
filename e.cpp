#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()

{
 int i,j,th=0,I;
 namedWindow("window1",WINDOW_NORMAL);
   
 createTrackbar("slider1","window1",&th,254);
  
   Mat img=imread("lena.png",0);
  
   Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));

   
    while(1)
     {      
     for(i=0;i<img.rows;i++){
       for(j=0;j<img.cols;j++){
     	 I=img.at<uchar>(i,j);
         if(img.at<uchar>(i,j) > th)      
        	a.at<uchar>(i,j)=255;
	else{
		a.at<uchar>(i,j)=0;	
	}
	             
	 }   
    }
	imshow("window1",a);
	waitKey(1);

       
     }
     waitKey(0);
     }
       
