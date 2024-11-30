#include "detect.h"

bool comparePoints(const cv::Point2f& p1, const cv::Point2f& p2) {
    return (p1.x+p1.y)<(p2.x+p2.y);
}

//绘制
void Armor_detector::draw_armor(cv::Mat &frame,Light &l,Armour &a) {
    for( auto & r : a.two_Light) {
        cv::Point2f point_rect[4];
        r.first.points(point_rect);
        
        cv::Point2f point_rect2[4];
        r.second.points(point_rect2);

        std::vector<cv::Point2f> points(point_rect,point_rect+4 );
        std::vector<cv::Point2f> points2(point_rect2,point_rect2+4 );

        std::sort(points.begin(),points.end(),comparePoints);
        std::sort(points2.begin(),points2.end(),comparePoints);

        if(points[0].x<points2[1].x) {
        cv::line(frame,points[0],points2[1],cv::Scalar(0,255,0),2,8,0);
        cv::line(frame,points2[1],points2[3],cv::Scalar(0,255,0),2,8,0);
        cv::line(frame,points2[3],points[2],cv::Scalar(0,255,0),2,8,0);
        cv::line(frame,points[2],points[0],cv::Scalar(0,255,0),2,8,0);
        }else {
            cv::line(frame,points2[0],points[1],cv::Scalar(0,255,0),2,8,0);
        cv::line(frame,points[1],points[3],cv::Scalar(0,255,0),2,8,0);
        cv::line(frame,points[3],points2[2],cv::Scalar(0,255,0),2,8,0);
        cv::line(frame,points2[2],points2[0],cv::Scalar(0,255,0),2,8,0);
        }
    }
}