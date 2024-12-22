#include "detect.h"
#include "pnpslover.h"
#include "MvCameraControl.h"
#include "HikDriver/HikDriver.h"
Armour a;
void test( const std::string &name,float light_height,float armor_width,float armor_height,float limit) {
 
    a.m_width=armor_width;
    a.m_height=armor_height;
    Light l;
    l.m_height=light_height;

    std::shared_ptr<Armour> a_ptr = std::make_shared<Armour>(a);
    Armor_detector ArmorDetector;
    ArmorDetector.show(name,a_ptr,l,limit);
}

//展示
void Armor_detector::show(std::string name,std::shared_ptr<Armour> &a_ptr,Light l,int limit) {

    HikDriver hik_driver(0);
    if (hik_driver.isConnected()) {
        //设置自动增益 曝光
        hik_driver.setAutoGain(1);
        hik_driver.setAutoExposureTime(1);
        // hik_driver.setExposureTime(4000);
        // hik_driver.setGain(15);
        hik_driver.showParamInfo();
        hik_driver.startReadThread();
    }
    while(true) {
        l.light_rect.clear();
        a_ptr->two_Light.clear();
        HikFrame Frame = hik_driver.getFrame();
        cv::Mat img = Frame.getRgbFrame()->clone();
        if (img.empty()) {
            continue;
        }
        //预处理
        cv::Mat frame = findLight_deal_frame(img,limit);
        //如果处理后的图像为空，直接显示图像
        if (frame.empty()) {
            std::cout<<"frame是空的"<<std::endl;
            cv::imshow("armor1",img);
        }else{
        //检测轮廓
        std::vector<std::vector<cv::Point>> contours = check_contours(frame);
        //检测灯条 
        detect_light(contours,l);
        //匹配灯条
        match_light( frame, l, *a_ptr );
        //匹配装甲板
        match_armour(l,*a_ptr);
        //绘制
        draw_armor(img,l,*a_ptr);
        cv::imshow("armor",img);
        //解pnp
        PnpSlover pnp;
        pnp.calculate_pnp( a, l);
        a_ptr->four_point.clear();
        }
        cv::waitKey(30);
    }
    //停止取流线程并释放资源
    hik_driver.stopReadThread();
    return;
}

using namespace std::chrono_literals;//在全局作用域中声明时间常量 简化代码

//表示创建一个 名为"armor_detector"的ros2节点类 options参数允许传递额外的节点选项
ArmorPubNode::ArmorPubNode(const rclcpp::NodeOptions &options) :
    Node("armor_detector",options),
    a_ptr(std::make_shared<Armour>())//使用智能指针管理Armor对象
{
    //创建消息发布器
    //rclcpp::SensorDataQoS() 表示使用传感器数据的质量服务（QoS）。该QoS设置有助于确保图像数据等高频传输的数据在网络拥堵时也能保证合适的传输性能。
    m_armors_publish = this->create_publisher<armor_interfaces::msg::Armor>("/armor",rclcpp::SensorDataQoS());
    m_detect_core = std::thread([this]()->void {
        //启动一个线程
        armor_interfaces::msg::Armor armor_msg;
         /**
        *param: 路径 灯条 高 装甲板宽 装甲板高 二值化阈值 
        */
        //test("1.avi",6,13.5,10,80);
        //test("2.avi",6,13.5,10,200);
        //test("3.avi",6,13.5,10,250);
        test("4.mp4",5.5,13.04,12,150);
        //test("5.mp4",6,13.5,10,150);
        //test("6.mp4",6,13.5,10,150);
        while (rclcpp::ok()) {
            armor_msg.number = 10;
            armor_msg.color = "Blue" ;

            //四元数
            armor_msg.pose.orientation.x = a.orientation[0];
            armor_msg.pose.orientation.y = a.orientation[1];
            armor_msg.pose.orientation.z = a.orientation[2]; 
            armor_msg.pose.orientation.w = a.orientation[3];
            //三维中心坐标
            armor_msg.pose.position.x = a.point_3D_center.x;
            armor_msg.pose.position.y = a.point_3D_center.y;
            armor_msg.pose.position.z = a.point_3D_center.z; 
            //四个特征点
            for ( int i = 0; i < 4; i ++ ) {
                armor_msg.apexs[i].x= a.four_point[i].x;
                armor_msg.apexs[i].y=a.four_point[i].y;
                armor_msg.apexs[i].z=0.0f;
            }
            //发布更新的消息
            m_armors_publish->publish(armor_msg);
        }
    });
}

//这行代码将 ArmorPubNode 类注册为一个可加载的 ROS 2 组件
// 在ROS 2 系统中动态加载和卸载。
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(ArmorPubNode);
