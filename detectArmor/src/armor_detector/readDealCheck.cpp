#include "detect.h"

//构造函数
Armor_detector::Armor_detector(): m_cap(0) {
}

//读取图像
cv::Mat Armor_detector::read_frame() {
    cv::Mat frame;
    m_cap >> frame;
    if(frame.empty()) {
        std::cout<<"end"<<std::endl;
        return cv::Mat();
    }
    return frame;
}


//预处理
cv::Mat Armor_detector::findLight_deal_frame(cv::Mat frame,int limit) {
    //转化为灰度图
    cv::Mat gray;
    cv::cvtColor(frame,gray,cv::COLOR_BGR2GRAY);
    //二值化图像
    cv::Mat binary;
    cv::threshold(gray,binary,limit,255,cv::THRESH_BINARY);
    cv::imshow("binary",binary);  
    return binary;
}

//检测轮廓
std::vector<std::vector<cv::Point>> Armor_detector::check_contours(cv::Mat preprocessing_frame) {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(preprocessing_frame,contours,hierarchy,cv::RETR_TREE,cv::CHAIN_APPROX_SIMPLE);
    return contours;
}