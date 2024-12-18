#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/armor_msg.h"
#include "tutorial_interfaces/msg/armor_msg.hpp"  // 导入自定义消息

class ArmorSubscriber : public rclcpp::Node {
public:
    ArmorSubscriber() : Node("armor_subscriber") {
        //创建一个订阅者
        subscription_ = this->create_subscription<tutorial_interfaces::msg::ArmorMsg>(
            "/armor",//订阅/armor话题
            10,
            std::bind(&ArmorSubscriber::callback, this, std::placeholders::_1));//std::placeholders::_1是一个占位符
    }

private:
    void callback(const tutorial_interfaces::msg::ArmorMsg::SharedPtr msg) {
        //输出日志
        RCLCPP_INFO(this->get_logger(), "Received ArmorMsg:");
        
        // 打印 pixels
        for (size_t i = 0; i < msg->pixels.size(); ++i) {
            const auto &pixel = msg->pixels[i];
            RCLCPP_INFO(this->get_logger(), "特征点 %ld: [%.2f, %.2f, %.2f]", i, pixel.x, pixel.y, pixel.z);
        }
        
        // 打印 pose
       RCLCPP_INFO(this->get_logger(), "Pose position: [%.2f, %.2f, %.2f] Orientation: [%.2f, %.2f, %.2f, %.2f]",
            msg->pose.position.x,
            msg->pose.position.y,
            msg->pose.position.z,
            msg->pose.orientation.x,
            msg->pose.orientation.y,
            msg->pose.orientation.z,
            msg->pose.orientation.w);

    }
    rclcpp::Subscription<tutorial_interfaces::msg::ArmorMsg>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ArmorSubscriber>());
    rclcpp::shutdown();
    return 0;
}