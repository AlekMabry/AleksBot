#include "opencv2/opencv.hpp"
#include "BlobDetection.h"

using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    namedWindow("edges", 1);
    Mat frame;

    BlobReturn blobData;

    for(;;) {
        cap >> frame;
        blobData = BlobDetection::blobDetect(frame);
        frame = blobData.frameOutput;
        imshow("edges", frame);
        if (waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}