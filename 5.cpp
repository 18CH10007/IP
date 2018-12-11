#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main()
{
      Mat s,h;
      s = imread("pexels-photo-1624254.jpeg", CV_LOAD_IMAGE_GRAYSCALE);
      h = imread("pexels-photo-1624254.jpeg", CV_LOAD_IMAGE_GRAYSCALE);

      int window[9];
        namedWindow("final",WINDOW_NORMAL);
        namedWindow("IMG",WINDOW_NORMAL);
      
        Mat d(s.rows,s.cols,CV_8UC1,Scalar(0));
     
        d = s.clone();
        for(int y = 0; y < s.rows; y++)
            for(int x = 0; x < s.cols; x++)
                d.at<uchar>(y,x) = 0.0;
             


        for(int y = 1; y < s.rows - 1; y++){
            for(int x = 1; x < s.cols - 1; x++){

                

                window[0] = s.at<uchar>(y - 1 ,x - 1);
                window[1] = s.at<uchar>(y, x - 1);
                window[2] = s.at<uchar>(y + 1, x - 1);
                window[3] = s.at<uchar>(y - 1, x);
                window[4] = s.at<uchar>(y, x);
                window[5] = s.at<uchar>(y + 1, x);
                window[6] = s.at<uchar>(y - 1, x + 1);
                window[7] = s.at<uchar>(y, x + 1);
                window[8] = s.at<uchar>(y + 1, x + 1);

                for(int k=0;k<9;++k)
                {if(window[k]==0)
                {
                    window[4]=255;
                }
            }
                for(int k=0;k<9;++k)
                    d.at<uchar>(y,x)=window[k];
                
            }
        }

        imshow("final", d);
         imshow("IMG", h);


        
        
    
    

      waitKey(0);


    return 0;
}


