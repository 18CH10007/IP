#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(){
Mat a(320,320,CV_8UC3, Scalar(0,223,255));
int x=a.at<Vec3b>(2,5)[2];
namedWindow("window1", WINDOW_NORMAL);
imshow("window1", a);
waitKey(0);
}
