#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "hsvrange.hpp"
using namespace cv;

Mat hsvFilter(Mat, Mat, Mat);
Mat bitwiseOr(Mat, Mat);
Mat findRetroreflectiveTape(Mat);