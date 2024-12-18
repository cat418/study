#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/armor_msg.h"
#include "tutorial_interfaces/msg/armor_msg.hpp"  // 导入自定义消息

class ArmorPublisher : public rclcpp::Node {
public:
    ArmorPublisher() : Node("armor_publisher") {
        publisher_ = this->create_publisher<tutorial_interfaces::msg::ArmorMsg>("/armor", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(500),
            std::bind(&ArmorPublisher::publishMessage, this));
    }

private:
    void publishMessage() {
        auto message = tutorial_interfaces::msg::ArmorMsg();
        
        // 填充 pixels
        geometry_msgs::msg::Point p1, p2, p3, p4;
        p1.x = 0.0; p1.y = 0.0; p1.z = 0.0;
        p2.x = 1.0; p2.y = 0.0; p2.z = 0.0;
        p3.x = 1.0; p3.y = 1.0; p3.z = 0.0;
        p4.x = 0.0; p4.y = 1.0; p4.z = 0.0;
        message.pixels = {p1, p2, p3, p4};
        
        // 填充 pose
        message.pose.position.x = 1.0;
        message.pose.position.y = 2.0;
        message.pose.position.z = 3.0;
        message.pose.orientation.w = 1.0;  // 单位四元数
        
        RCLCPP_INFO(this->get_logger(), "Publishing ArmorMsg");
        publisher_->publish(message);
    }

    rclcpp::Publisher<tutorial_interfaces::msg::ArmorMsg>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ArmorPublisher>());
    rclcpp::shutdown();
    return 0;
}