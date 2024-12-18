#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/armor_msg.h"
#include "tutorial_interfaces/msg/armor_msg.hpp"  // 导入自定义消息

class ArmorSubscriber : public rclcpp::Node {
public:
    ArmorSubscriber() : Node("armor_subscriber") {
        subscription_ = this->create_subscription<tutorial_interfaces::msg::ArmorMsg>(
            "/armor",
            10,
            std::bind(&ArmorSubscriber::callback, this, std::placeholders::_1));
    }

private:
    void callback(const tutorial_interfaces::msg::ArmorMsg::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received ArmorMsg:");
        
        // 打印 pixels
        for (size_t i = 0; i < msg->pixels.size(); ++i) {
            const auto &pixel = msg->pixels[i];
            RCLCPP_INFO(this->get_logger(), "Pixel %ld: [%.2f, %.2f, %.2f]", i, pixel.x, pixel.y, pixel.z);
        }
        
        // 打印 pose
        RCLCPP_INFO(this->get_logger(), "Pose: [%.2f, %.2f, %.2f]",
                    msg->pose.position.x,
                    msg->pose.position.y,
                    msg->pose.position.z);
    }

    rclcpp::Subscription<tutorial_interfaces::msg::ArmorMsg>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ArmorSubscriber>());
    rclcpp::shutdown();
    return 0;
}