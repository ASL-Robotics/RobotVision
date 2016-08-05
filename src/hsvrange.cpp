#include "hsvrange.hpp"

HSVRange::HSVRange() {
  hRange[0] = 0;
  hRange[1] = 0;
  sRange[0] = 0;
  sRange[1] = 0;
  vRange[0] = 0;
  vRange[1] = 0;
}

HSVRange::HSVRange(double hMin, double hMax, double sMin, double sMax, double vMin, double vMax) {
  hRange[0] = hMin;
  hRange[1] = hMax;
  sRange[0] = sMin;
  sRange[1] = sMax;
  vRange[0] = vMin;
  vRange[1] = vMax;
}

Scalar HSVRange::minValues() {
  return Scalar(hRange[0], sRange[0], vRange[0]);
}

Scalar HSVRange::maxValues() {
  return Scalar(hRange[1], sRange[1], vRange[1]);
}