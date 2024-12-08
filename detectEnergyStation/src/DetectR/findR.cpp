#include "detect.h"

//寻找R
void DetectR::findR(Detect & detect,DetectR &R) {
    std::vector<std::vector<cv::Point>> contours;
    //遍历轮廓
    for( int i = 0; i < detect.m_allContours.size(); i ++ ) {
        //根据面积筛选
        if( cv::contourArea( detect.m_allContours[i] ) <40 || cv::contourArea( detect.m_allContours[i] ) > 1000 ) {
            continue;
        }
        //根据轮廓筛选 有子轮廓 没有父轮廓
        int son = detect.m_hierarchy[i][2];
        if( detect.m_hierarchy[i][2] != -1 && detect.m_hierarchy[i][3] == -1 && detect.m_hierarchy[son][2] == -1 ) {
            contours.push_back( detect.m_allContours[i] );
        }
    }

    std::sort( contours.begin(), contours.end(),[](const std::vector<cv::Point> contour1, std::vector<cv::Point> contour2){
        return cv::contourArea( contour1 ) < cv::contourArea( contour2 );
    });

    R.m_contours.push_back( contours[0] );
}