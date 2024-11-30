#include "detect.h"

//检测灯条 
void Armor_detector::detect_light(std::vector<std::vector<cv::Point>> contours,Light &l) { 
    //最小外接矩形拟合灯条
    std::vector<cv::RotatedRect> allRotatedRect;
    //根据面积筛选
    for(const auto & l : contours) {
        if(cv::contourArea(l)>50) {
            cv::RotatedRect rect = cv::minAreaRect(l);
            allRotatedRect.push_back(rect);
        }
    }
    l.light_rect = allRotatedRect;
}

