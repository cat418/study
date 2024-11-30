#include "detect.h"

//匹配灯条
void Armor_detector::match_light( cv::Mat frame, Light &l, Armour &a) {
    //将灯条的矩形两两配对
    std::vector<bool> matched(l.light_rect.size(),false);
    for( int i =0; i < l.light_rect.size(); i ++ ) {
        if( matched[i] ) continue;
        cv::RotatedRect rect1 = l.light_rect[i];
        for( int j = i+1; j < l.light_rect.size(); j ++) {
        if( matched[j] ) continue;
        cv::RotatedRect rect2 = l.light_rect[j];
        //根据平行匹配灯条
        float angle_diff = abs(rect1.angle - rect2.angle);
        if( angle_diff > 180.0 ) {
            angle_diff = 360.0 - angle_diff;
        }
        if( angle_diff > 45 ) {
            angle_diff = 90 - angle_diff;
        }
        //根据灯条颜色匹配灯条
        LightColor rect1_color = l.getColor( frame, rect1);
        LightColor rect2_color = l.getColor( frame, rect2);
        //根据面积匹配 
        float area1 = l.light_rect[i].size.height * l.light_rect[i].size.width ;
        float area2 = l.light_rect[j].size.height * l.light_rect[j].size.width ;

        if( angle_diff < 20 && rect1_color == rect2_color && rect1_color == l.enemy_color && abs(area1 - area2) < 500 ) {
                a.two_Light.push_back( std::make_pair( rect1, rect2 ) );
                matched[i] = true;//标记已匹配
                matched[j] = true;//标记已匹配
            }
        }
    }
}