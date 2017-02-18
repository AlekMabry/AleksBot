#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        Mat edges;
        Mat contoursFrame;
        vector<vector<Point> > contours;
        vector<Vec4i> hierarchy;

        cap >> frame; // get a new frame from camera
        GaussianBlur(frame, edges, Size(7,7), 1.5, 1.5);
        cvtColor(edges, edges, COLOR_BGR2HSV);
        inRange(edges, Scalar(36, 152, 50), Scalar(113, 255, 255), edges);
        findContours( edges.clone(), contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
        drawContours(frame, contours, -1, Scalar(255, 0, 0), 1, 8, hierarchy);
        imshow("edges", frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}