#include "BlobDetection.h"

BlobReturn BlobDetection::blobDetect(Mat frame) {
    Mat edges;
    Mat contoursFrame;
    vector <vector<Point> > contours;
    vector <Vec4i> hierarchy;
    int largest_area = 0;
    int largest_contour_index = 0;

    GaussianBlur(frame, edges, Size(7, 7), 1.5, 1.5);
    cvtColor(edges, edges, COLOR_BGR2HSV);
    inRange(edges, Scalar(36, 152, 50), Scalar(113, 255, 255), edges);
    findContours(edges.clone(), contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    double xPos;
    double yPos;

    if (contours.size() > 0) {
        vector <Moments> mu(contours.size());
        vector <Point2f> mc(contours.size());
        for (int i = 0; i < contours.size(); i++) {
            mu[i] = moments(contours[i], false);
            mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
            xPos = mu[i].m10 / mu[i].m00;
            yPos = mu[i].m01 / mu[i].m00;
            double a = contourArea(contours[i], false);
            if (largest_area < a) {
                largest_area = a;
                largest_contour_index = i;
            }
        }
        circle(frame, mc[largest_contour_index], 4, Scalar(255, 0, 0), -1, 8, 0);
        drawContours(frame, contours, largest_contour_index, Scalar(255, 0, 0), 1, 8, hierarchy);
    }

    BlobReturn returnValue;
    returnValue.frameOutput = frame;
    returnValue.xPosOutput = xPos;
    returnValue.yPosOutput = yPos;
    return returnValue;
}
