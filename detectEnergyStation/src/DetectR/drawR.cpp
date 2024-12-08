#include "detect.h"

//绘制R
void DetectR::drawR( cv::Mat &frame, cv::Mat &gary, DetectR R ) {
    for( auto & m : R.m_contours ) {
        cv::Point2f center;
        float r;
        cv::minEnclosingCircle( m, center, r );
        cv::circle( frame,center, r, cv::Scalar(0,255,0), 2);
        cv::circle( gary,center, r, cv::Scalar(255), 2);
    }
}