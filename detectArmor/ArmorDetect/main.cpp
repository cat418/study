#include "detect.h"
#include <stdio.h>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/video/video.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include "HikDriver/HikDriver.h"

void test( const std::string &name,float light_height,float armor_width,float armor_height,float limit) {
    Armour a;
    a.m_width=armor_width;
    a.m_height=armor_height;
    Light l;
    l.m_height=light_height;

    Armor_detector ArmorDetector;
    ArmorDetector.show(name,a,l,limit);
}

int main() {
    /**
    *param: 路径 灯条 高 装甲板宽 装甲板高 二值化阈值 
    */
    //test("1.avi",6,13.5,10,80);
    //test("2.avi",6,13.5,10,200);
    //test("3.avi",6,13.5,10,250);
    test("4.mp4",6,13.5,10,150);
    //test("5.mp4",6,13.5,10,150);
    //test("6.mp4",6,13.5,10,150);
}