#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include<math.h>
using namespace cv;
using namespace std;
int main()

{
 int i,j,an;
 namedWindow("window1",WINDOW_NORMAL);
   
 
  
   Mat img=imread("fruits.png",0);
   	 Mat a(2*img.rows,2*img.cols,CV_8UC3,Scalar(0));
   namedWindow("window1",WINDOW_NORMAL);

double sinus = abs(sin(rotateAmount*PI/180));
    double cosinus = abs(cos(rotateAmount*PI/180));
    for (int y=0; y<image.rows; y++) {
        for (int x = 0; x< image.cols; x++) {
            
            int tempX = round((x*cosinus + y*sinus));
            //x*(cos(rotateAmount) - sin(rotateAmount));
            int tempY = round((y*cosinus + x*sinus));
            //y*( sin(rotateAmount) - cos(rotateAmount));
            a.at<vec3b>(y,x) = img.at<vec3b>(tempY,tempX);
        }
    }
   } imshow("window1",img);
     imshow("IMG",a);
     waitKey(0);
     }