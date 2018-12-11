#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
Mat img=imread("fruits.png",1);
namedWindow("IMG", WINDOW_NORMAL);
imshow("IMG", img);
waitKey(0);
}
