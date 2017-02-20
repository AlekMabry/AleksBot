#include "opencv2/opencv.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "opencv2/highgui/highgui.hpp"

#ifndef ROBOCORE_BLOBDETECTION_H
#define ROBOCORE_BLOBDETECTION_H

using namespace cv;
using namespace std;

class BlobDetection {
public:
    static Mat blobDetect(Mat frame);
};


#endif //ROBOCORE_BLOBDETECTION_H
