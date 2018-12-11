#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

//sort the window using insertion sort
//insertion sort is best for this sorting
int main()
{
      Mat src, dst;

      // Load an image
      src = imread("index.jpg", CV_LOAD_IMAGE_GRAYSCALE);

      int window[10];

        dst = src.clone();
        for(int y = 0; y < src.rows; y++)
            for(int x = 0; x < src.cols; x++)
                dst.at<uchar>(y,x) = 0.0;
        

        for(int y = 1; y < src.rows - 1; y++){
            for(int x = 1; x < src.cols -1;x++){

                window[0] = src.at<uchar>(y - 1 ,x - 1);
                window[1] = src.at<uchar>(y, x - 1);
                window[2] = src.at<uchar>(y + 1, x - 1);
                window[3] = src.at<uchar>(y - 1, x);
                window[4] = src.at<uchar>(y, x);
                window[5] = src.at<uchar>(y + 1, x);
                window[6] = src.at<uchar>(y - 1, x + 1);
                window[7] = src.at<uchar>(y, x + 1);
                window[8] = src.at<uchar>(y + 1, x + 1);

                window[9] = (((window[0]+window[2]+window[6]+window[8])/16)+((window[1]+window[3]+window[5]+window[7])/8)+(window[4])/4);
                dst.at<uchar>(y,x)=window[9];
            }
        }

        namedWindow("final");
        imshow("final", dst);

        namedWindow("initial");
        imshow("initial", src);

      waitKey();


    return 0;
}


