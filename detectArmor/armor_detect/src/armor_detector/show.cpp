#include "detect.h"
#include "pnpslover.h"
#include "MvCameraControl.h"
#include "HikDriver/HikDriver.h"

//展示
void Armor_detector::show(std::string name,Armour a,Light l,int limit) {

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
        a.two_Light.clear();
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
        match_light( frame, l, a );
        //匹配装甲板
        match_armour(l,a);
        //绘制
        draw_armor(img,l,a);
        cv::imshow("armor",img);
        //解pnp
        PnpSlover pnp;
        pnp.calculate_pnp( a, l);
        a.four_point.clear();
        }
        cv::waitKey(30);
    }
    //停止取流线程并释放资源
    hik_driver.stopReadThread();
    return;
}