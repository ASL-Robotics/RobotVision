#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace cv;

int main(int argc, char** argv )
{
    VideoCapture cam(0);
    //cam.open(0);
    Mat image;
    /*
    if(argc > 1 && strcmp(argv[1], "--mac")) {
      cam.set(CV_CAP_PROP_FRAME_WIDTH , 640); 
      cam.set(CV_CAP_PROP_FRAME_HEIGHT , 480); 
      cam.set (CV_CAP_PROP_FOURCC, CV_FOURCC('B', 'G', 'R', '3'));
    }
    */
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    cam >> image;

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}