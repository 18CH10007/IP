#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()

{
 int i,j,I;

   Mat img=imread("lena.png",0);
   namedWindow("IMG",WINDOW_NORMAL);

   Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));

   namedWindow("window1",WINDOW_NORMAL);
          
     for(i=0;i<img.rows;i++){
       for(j=0;j<img.cols;j++){
     	 I=img.at<uchar>(i,j);
         if(I>10)  
          I=255;
         else
          I=0;
	a.at<uchar>(i,j)=I;
         }
        }
     	
         
     
     imshow("window1",img);
     imshow("IMG",a);
     waitKey(0);
     }
       
