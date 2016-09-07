#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "hsvrange.hpp"

using namespace cv;

#define MIN_AREA 1500

Mat hsvFilter(Mat, Mat, Mat);
Mat bitwiseOr(Mat, Mat);
Mat findRetroreflectiveTape(Mat);
void renderAllContours(Mat src, vector< vector<Point> > contours, vector<Vec4i> hierarchy);
void renderSelectContours(Mat src, vector< vector<Point> > contours, vector<Vec4i> hierarchy, vector<int> idxs);
vector<int> filterContours(Mat src, vector< vector<Point> > contours, vector<Vec4i> hierarchy);