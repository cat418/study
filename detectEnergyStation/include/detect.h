#ifndef _DETECT_H_
#define _DETECT_H_
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

class Detect;

class DetectR
{
public:
    DetectR();
    ~DetectR() = default;
    //寻找R
    void findR( Detect & detect, DetectR &R );
    //绘制R
    void drawR( cv::Mat &frame, cv::Mat &gray, DetectR R );
public:
    std::vector<std::vector<cv::Point>> m_contours;

};

class DetectBuff
{

};

class Detect
{
public:
    Detect();
    ~Detect() = default;
    //读取图像
    cv::Mat readFrame();
    //处理图像
    cv::Mat dealFrame( cv::Mat frame );
    //检测轮廓
    void checkContours( cv::Mat frame, Detect &detect );
    //展示
    void show( std::string name, DetectR &R);
public:
    cv::VideoCapture m_cap;
    int m_FPS;
    std::vector<std::vector<cv::Point>> m_allContours;
    std::vector<cv::Vec4i> m_hierarchy;
};

#endif
