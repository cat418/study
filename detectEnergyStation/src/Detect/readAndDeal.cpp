#include "detect.h"

cv::Mat Detect::readFrame() {
    cv::Mat frame;
    m_cap >> frame;
    if( frame.empty() ) {
        return cv::Mat();
    }
    return frame;
}

cv::Mat Detect::dealFrame( cv::Mat frame ) {
    //转化为灰度图
    cv::Mat gray;
    cv::cvtColor( frame, gray, cv::COLOR_BGR2GRAY );
    //二值化
    cv::threshold( gray, gray, 200, 255, cv::THRESH_BINARY );

    //通道分离
    cv::Mat img[3];
    cv::split( frame, img );
    cv::Mat r_b = img[2] - img[0];
    //二值化
    cv::threshold( r_b, r_b, 10, 255, cv::THRESH_BINARY);

    //取交集
    cv::Mat result;
    cv::bitwise_and( r_b, gray, result);
    //闭运算
    cv::Mat kernel = cv::getStructuringElement( 2, cv::Size(3,3));
    cv::morphologyEx( result, result, cv::MORPH_CLOSE, kernel);
    cv::imshow("2",result);
    return result;
}