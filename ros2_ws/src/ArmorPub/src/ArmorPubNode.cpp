#include "ArmorPubNode.h"

using namespace std::chrono_literals;//在全局作用域中声明时间常量 简化代码

//表示创建一个 名为"armor_detector"的ros2节点类 options参数允许传递额外的节点选项
ArmorPubNode::ArmorPubNode(const rclcpp::NodeOptions &options) :
    Node("armor_detector",options)
{
    //创建消息发布器
    //rclcpp::SensorDataQoS() 表示使用传感器数据的质量服务（QoS）。该QoS设置有助于确保图像数据等高频传输的数据在网络拥堵时也能保证合适的传输性能。
    m_armors_publish = this->create_publisher<armor_interfaces::msg::Armor>("/armor",rclcpp::SensorDataQoS());
    m_detect_core = std::thread([this]()->void {
        //启动一个线程
        armor_interfaces::msg::Armor armor_msg;
        while (1) {
            std::cout << "run thread" << std::endl;
            armor_msg.number = 10;
            armor_msg.color = "Blue" ;
            for ( int i = 0; i < 4; i ++ ) {
                armor_msg.apexs[i].x = i;
            }
            armor_msg.pose.orientation.x = 10;
            armor_msg.pose.orientation.y = 20;
            armor_msg.pose.orientation.z = 30; 
            armor_msg.pose.orientation.w = 40;
            m_armors_publish->publish(armor_msg);
        }
    });
}

//这行代码将 ArmorPubNode 类注册为一个可加载的 ROS 2 组件
// 在ROS 2 系统中动态加载和卸载。
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(ArmorPubNode);
