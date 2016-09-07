#include "main.hpp"

//const double hRange[] = {75, 95}, sRange[] = {180, 255}, vRange[] = {60, 170};

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

  Mat filtered = findRetroreflectiveTape(image);
  
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  findContours( filtered, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
  vector<int> filteredContours = filterContours(filtered, contours, hierarchy);

  renderSelectContours(Mat(image.size(), image.type(), Scalar(0,0,0,0)), contours, hierarchy, filteredContours);

  waitKey(0);
  return 0;
}

Mat findRetroreflectiveTape(Mat image) {
  Mat eroded(image.size(), image.type(), Scalar(0,0,0,0));
  Mat dilated(image.size(), image.type(), Scalar(0,0,0,0));
  erode(bitwiseOr(hsvFilter(image, hsvlow1, hsvhigh1), hsvFilter(image, hsvlow2, hsvhigh2)), eroded, Mat());
  dilate(eroded, dilated, Mat());
  return dilated;
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

void renderAllContours(Mat src, vector< vector<Point> > contours, vector<Vec4i> hierarchy) {
    // iterate through all the top-level contours,
    // draw each connected component with its own random color
    int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        Scalar color( rand()&255, rand()&255, rand()&255 );
        drawContours( src, contours, idx, color, CV_FILLED, 8, hierarchy );
    }

    namedWindow( "Components", 1 );
    imshow( "Components", src );
}

void renderSelectContours(Mat src, vector< vector<Point> > contours, vector<Vec4i> hierarchy, vector<int> idxs) {
    // iterate through all the top-level contours,
    // draw each connected component with its own random color
    for(int idx: idxs)
    {
        Scalar color( rand()&255, rand()&255, rand()&255 );
        drawContours( src, contours, idx, color, CV_FILLED, 8, hierarchy );
    }

    namedWindow( "Components", 1 );
    imshow( "Components", src );
}

vector<int> filterContours(Mat src, vector< vector<Point> > contours, vector<Vec4i> hierarchy) {
    // iterate through all the top-level contours,
    // filter each one
    vector<int> idxs;
    Rect bb;
    double area;

    int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        bb = boundingRect(contours[idx]);
        area = contourArea(contours[idx]);

        if(area < MIN_AREA)
            continue;
        
        idxs.push_back(idx);
        std::cout << bb << std::endl;
        std::cout << area << std::endl;
    }

    return idxs;
}