#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
Mat img=imread("lena.png",0);
namedWindow("IMG",WINDOW_NORMAL);

Mat a(img.rows,img.cols,CV_8UC1,Scalar(0));
namedWindow("window1",WINDOW_NORMAL);


for(int j=0;j<img.cols;j++){
 for(int i=0;i<img.rows;i++){
  int x=img.at<uchar>(i,j);
   if(x>150){
   x=255;
   }
   else 
   {x=0;}
   a.at<uchar>(i,j)=x;
 }
}
imshow("window1",a);
imshow("IMG",img);
waitKey(5000);
}
