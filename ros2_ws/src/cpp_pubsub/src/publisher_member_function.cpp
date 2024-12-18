#include "rclcpp/rclcpp.hpp"//包含节点，发布者，定时器
#include "tutorial_interfaces/msg/armor_msg.h"//自定义消息类型声明文件
#include "tutorial_interfaces/msg/armor_msg.hpp"  //自定义消息定义文件

using namespace std::chrono_literals;//在全局作用域中声明时间常量 简化代码

//表示是一个ros2节点类
class ArmorPublisher : public rclcpp::Node {
public:
//节点命名为 armor_publisher
    ArmorPublisher() : Node("armor_publisher") {
        //创建一个消息发布者 发布类型是ArmorMsg 话题名为/armor 队列大小为10
        publisher_ = this->create_publisher<tutorial_interfaces::msg::ArmorMsg>("/armor", 10);
        timer_ = this->create_wall_timer(
            //创建一个定时器 消息每 500ms触发一次
            500ms,
            //atd::bind是c++库中的一个模板类 他的作用是创建一个新的可调用对象
            std::bind(&ArmorPublisher::publishMessage, this));
    }

private:
    void publishMessage() {
        //创建一个ArmorMsg消息对象 message 
        auto message = tutorial_interfaces::msg::ArmorMsg();
        
        // 填充 pixels 表示四个点
        geometry_msgs::msg::Point p1, p2, p3, p4;
        p1.x = 0.0; p1.y = 0.0; p1.z = 0.0;
        p2.x = 1.0; p2.y = 0.0; p2.z = 0.0;
        p3.x = 1.0; p3.y = 1.0; p3.z = 0.0;
        p4.x = 0.0; p4.y = 1.0; p4.z = 0.0;
        message.pixels = {p1, p2, p3, p4};
        
        // 填充 pose 
        //位置
        message.pose.position.x = 1.0;
        message.pose.position.y = 2.0;
        message.pose.position.z = 3.0;
        //姿态
        message.pose.orientation.w = 1.0;  // 单位四元数
        //输出日志 表示消息正在发布
        RCLCPP_INFO(this->get_logger(), "Publishing ArmorMsg");
        //发布消息
        publisher_->publish(message);
    }
//rclcpp::Publisher是一个模板类 用于发布ROS2消息 参数是消息类型  SharedPtr智能指针
    rclcpp::Publisher<tutorial_interfaces::msg::ArmorMsg>::SharedPtr publisher_;
    // rclcpp::TimerBase是一个基类 是一个定时器 ros2中的定时器通常用于周期性的回调某个回调函数
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);//初始化ROS2系统
    rclcpp::spin(std::make_shared<ArmorPublisher>());//启动ROS2事件循环
    rclcpp::shutdown();//在节点退出时关闭ROS2系统
    return 0;
}