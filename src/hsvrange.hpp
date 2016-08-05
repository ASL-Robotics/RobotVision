#include <opencv2/opencv.hpp>
using namespace cv;

class HSVRange {
  public:
    double hRange[2];
    double sRange[2];
    double vRange[2];
    HSVRange (double, double, double, double, double, double);
    HSVRange ();
    Scalar minValues();
    Scalar maxValues();
} ;