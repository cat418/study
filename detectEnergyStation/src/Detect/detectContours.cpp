#include "detect.h"

void Detect::checkContours( cv::Mat frame, Detect &detect ) {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarghy;
    cv::findContours( frame, contours, hierarghy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE );
    detect.m_allContours = contours;
    detect.m_hierarchy = hierarghy;
}