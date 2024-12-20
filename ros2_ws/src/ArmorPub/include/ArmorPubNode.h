#ifndef ARMOR_PUB_NODE_H
#define ARMOR_PUB_NODE_H

#include <iostream>
#include <thread>
#include <memory.h>//c语言的内存操作头文件 通常用于直接操作内存

#include <rclcpp/rclcpp.hpp>
//用于ros2中传输图像消息
#include <image_transport/publisher.hpp>
#include <image_transport/subscriber_filter.hpp>
#include <image_transport/image_transport.hpp>

#include <opencv2/opencv.hpp>
//自定义消息类型
#include "armor_interfaces/msg/armor.hpp"

class ArmorPubNode : public rclcpp::Node{
public:
    ArmorPubNode(const rclcpp::NodeOptions &options);
private:
    //发布消息
    rclcpp::Publisher<armor_interfaces::msg::Armor>::SharedPtr m_armors_publish;
    //线程对象
    std::thread m_detect_core;
};

#endif //ARMOR_DETECT_NODE_H