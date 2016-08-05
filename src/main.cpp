#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "hsvrange.hpp"
using namespace cv;

//const double hRange[] = {75, 95}, sRange[] = {180, 255}, vRange[] = {60, 170};
Mat hsvFilter(Mat, Mat, Mat);
Mat bitwiseOr(Mat, Mat);
Mat findRetroreflectiveTape(Mat);

HSVRange range1(75, 95, 180, 255, 60, 170);
HSVRange range2(65, 155, 25, 125, 125, 215);

Mat hsvlow1;
Mat hsvhigh1;
Mat hsvlow2;
Mat hsvhigh2;

int main(int argc, char **argv) {
  if(argc != 2) {
    printf("usage: <program name> <path to image>\n");
    return -1;
  }
  
  Mat image = imread(argv[1], 1);
  
  if ( !image.data )
  {
      printf("No image data \n");
      return -1;
  }
  
  //Initialize Global Variables
  hsvlow1 = Mat(image.size(), image.type(), range1.minValues());
  hsvhigh1 = Mat(image.size(), image.type(), range1.maxValues());
  hsvlow2 = Mat(image.size(), image.type(), range2.minValues());
  hsvhigh2 = Mat(image.size(), image.type(), range2.maxValues());
  
  namedWindow("Display Image", WINDOW_AUTOSIZE );
  imshow("Display Image", findRetroreflectiveTape(image));
  waitKey(0);
  return 0;
}

Mat findRetroreflectiveTape(Mat image) {
  return bitwiseOr(hsvFilter(image, hsvlow1, hsvhigh1), hsvFilter(image, hsvlow2, hsvhigh2));
}

Mat hsvFilter(Mat input, Mat low, Mat high) {
  Mat hsv(input.size(), input.type(), Scalar(0,0,0,0));
  Mat out(input.size(), input.type(), Scalar(0,0,0,0));
  cvtColor(input, hsv, COLOR_BGR2HSV);
  inRange(hsv, low, high, out);
  return out;
}

Mat bitwiseOr(Mat input1, Mat input2) {
  Mat out(input1.size(), input1.type(), Scalar(0,0,0,0));
  bitwise_or(input1, input2, out);
  return out;
}