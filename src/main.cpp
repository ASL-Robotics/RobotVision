#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

//Ideal so far: 75, 95, 180, 255, 60, 170
const double hRange[] = {75, 95}, sRange[] = {180, 255}, vRange[] = {60, 170};
Mat hsvFilter(Mat, Mat, Mat);

int main(int argc, char **argv) {
  if(argc != 2) {
    printf("usage: <program name> <path to image>\n");
  }
  
  Mat image = imread(argv[1], 1);
  Mat hlslow(image.size(), image.type(), Scalar(hRange[0], sRange[0], vRange[0], 0));
  Mat hlshigh(image.size(), image.type(), Scalar(hRange[1], sRange[1], vRange[1], 0));
  
  if ( !image.data )
  {
      printf("No image data \n");
      return -1;
  }
  
  namedWindow("Display Image", WINDOW_AUTOSIZE );
  imshow("Display Image", hsvFilter(image, hlslow, hlshigh));
  waitKey(0);
  return 0;
}

Mat hsvFilter(Mat input, Mat low, Mat high) {
  Mat hsv(input.size(), input.type(), Scalar(0,0,0,0));
  Mat out(input.size(), input.type(), Scalar(0,0,0,0));
  cvtColor(input, hsv, COLOR_BGR2HSV);
  inRange(hsv, low, high, out);
  return out;
}