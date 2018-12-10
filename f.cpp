#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()

{
 int i,j,th=0,I1,I2,I3,I4,I5,I6;
 namedWindow("window1",WINDOW_NORMAL);
   
 createTrackbar("slider1","window1",&th,254);
 createTrackbar("slider2","window1",&th,254);
 createTrackbar("slider3","window1",&th,254);
 createTrackbar("slider4","window1",&th,254);
 createTrackbar("slider5","window1",&th,254);
 createTrackbar("slider6","window1",&th,254); 
   Mat img=imread("fruits.png",1);
  
   Mat a(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));

   
    while(1)
     {      
     for(i=0;i<img.rows;i++){
       for(j=0;j<img.cols;j++){
     	 I1=img.at<Vec3b>(i,j);
         I2=img.at<Vec3b>(i,j);
         I3=img.at<Vec3b>(i,j);
         I4=img.at<Vec3b>(i,j);
         I5=img.at<Vec3b>(i,j);
         I6=img.at<Vec3b>(i,j);
         if(img.at<Vec3b>(i,j) > th)      
        	(a.at<Vec3b>(i,j))=255;
	else{0,
		a.at<Vec3b>(i,j)=0;	
	}
	             
	 }   
    }
	imshow("window1",a);
	waitKey(1);

       
     }
     waitKey(0);
     }
       
