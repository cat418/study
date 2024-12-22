#ifndef _DETECT_H_
#define _DETECT_H_


#include <iostream>
#include <opencv2/opencv.hpp>
#include "HikDriver/HikDriver.h"

//类声明
class Light;

class Armour
{
/**
 *@brief: 装甲板的构造函数
 *@param: 装甲板的数据 
 */
public:
    Armour();
    ~Armour() = default;
public:
    float m_width;
    float m_height;
    std::vector<std::pair< cv::RotatedRect, cv::RotatedRect>> two_Light;
    std::vector<cv::Point2f> four_point;//二维坐标
    std::vector<float> orientation;//四元数
    cv::Point3f point_3D_center;
};

class Light
{
/**
 * @brief:灯条的构造函数
 * @param:灯条的数据
 */
public:
    Light();
    ~Light() = default;
   
public:
    float m_height;
    //获取灯条的旋转矩形
    std::vector<cv::RotatedRect> light_rect;
};

class Armor_detector
{
/**
 * @brief:装甲板识别流程
 */
public:

    //构造函数
    Armor_detector();
    //析构函数
    ~ Armor_detector() = default;
    //读取图像
    cv::Mat read_frame();
    //预处理
    cv::Mat findLight_deal_frame(cv::Mat frame,int limit);
    //检测轮廓
    std::vector<std::vector<cv::Point>> check_contours(cv::Mat preprocessing_frame);
    //检测灯条
    void detect_light(std::vector<std::vector<cv::Point>> contours,Light &l);
    //匹配灯条
    void match_light( cv::Mat frame, Light &l, Armour &a);
    //匹配装甲板 
    void match_armour(Light &l,Armour &a);
    //绘制
    void draw_armor(cv::Mat &frame,Light &l,Armour &a);
    //展示
    void show(std::string name,std::shared_ptr<Armour> &a_ptr,Light l,int limit);
private:
    cv::VideoCapture m_cap;
};

#include <thread>
#include <memory.h>//c语言的内存操作头文件 通常用于直接操作内存

#include <rclcpp/rclcpp.hpp>
//用于ros2中传输图像消息
#include <image_transport/publisher.hpp>
#include <image_transport/subscriber_filter.hpp>
#include <image_transport/image_transport.hpp>

#include "detect.h"
//自定义消息类型
#include "armor_interfaces/msg/armor.hpp"

//节点类
class ArmorPubNode : public rclcpp::Node{
public:
    ArmorPubNode(const rclcpp::NodeOptions &options);
private:
    //发布消息
    rclcpp::Publisher<armor_interfaces::msg::Armor>::SharedPtr m_armors_publish;
    //线程对象
    std::thread m_detect_core;
    //管理Armour的智能指针
    std::shared_ptr<Armour> a_ptr;
};

#endif