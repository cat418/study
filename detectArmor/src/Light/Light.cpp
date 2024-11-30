#include "detect.h"

Light::Light() {
    //初始化
    this->m_height = 0;
}

/**
 * @brief: 获取灯条颜色
 * @param: 每一帧图像 拟合灯条的旋转矩形
 */
LightColor Light::getColor( cv::Mat frame ,cv::RotatedRect light_Rect ) {
    cv::Mat light_frame;
    cv::getRectSubPix( frame, light_Rect.size, light_Rect.center, light_frame);

    cv::Scalar bgr_value = cv::mean( light_frame );
    double value_blue = bgr_value[0];
    double value_red = bgr_value[2];
    LightColor color;
    if( value_blue > value_red) {
        color = BLUE;
    }else{
        color = RED;
    }
        return color;
}
