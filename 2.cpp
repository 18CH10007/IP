#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

//sort the window using insertion sort
//insertion sort is best for this sorting
void insertionSort(int window[])
{
    int temp, i , j;
    for(i = 0; i < 9; i++){
        temp = window[i];
        for(j = i-1; j >= 0 && temp < window[j]; j--){
            window[j+1] = window[j];
        }
        window[j+1] = temp;
    }
}

int main()
{
      Mat src, dst;

      // Load an image
      src = imread("veg.jpg", CV_LOAD_IMAGE_GRAYSCALE);

      int window[9];

        dst = src.clone();
        for(int y = 0; y < src.rows; y++)
            for(int x = 0; x < src.cols; x++)
                dst.at<uchar>(y,x) = 0.0;

        for(int y = 1; y < src.rows - 1; y++){
            for(int x = 1; x < src.cols - 1; x++){

                // Pick up window element

                window[0] = src.at<uchar>(y - 1 ,x - 1);
                window[1] = src.at<uchar>(y, x - 1);
                window[2] = src.at<uchar>(y + 1, x - 1);
                window[3] = src.at<uchar>(y - 1, x);
                window[4] = src.at<uchar>(y, x);
                window[5] = src.at<uchar>(y + 1, x);
                window[6] = src.at<uchar>(y - 1, x + 1);
                window[7] = src.at<uchar>(y, x + 1);
                window[8] = src.at<uchar>(y + 1, x + 1);

                // sort the window to find median
                insertionSort(window);

                // assign the median to centered element of the matrix
                dst.at<uchar>(y,x) = window[4];
            }
        }

        namedWindow("final");
        imshow("final", dst);

        namedWindow("initial");
        imshow("initial", src);

      waitKey();


    return 0;
}


