#include "detect.h"
#include "pnpslover.h"
#include "MvCameraControl.h"
#include "camera_class.h"

//展示
void Armor_detector::show(std::string name,Armour a,Light l,int limit) {
   
    int key;
    camera cam;
    cam.start_cam();

    while(true) {
        l.light_rect.clear();
        a.two_Light.clear();
        //读取图像
        //cv::Mat frame=read_frame().clone();
        cv::Mat frame;
        cam.get_pic(&frame);
        if(frame.empty()) {
            std::cout<<"end"<<std::endl;
            break;
        }
        //预处理
        cv::Mat lightFrame = findLight_deal_frame(frame,limit);
        // 如果处理后的图像为空，直接显示图像
        if (lightFrame.empty()) {
            std::cout<<"lightFrame是空的"<<std::endl;
            cv::imshow("armor1",frame);
        }else{
        //检测轮廓
        std::vector<std::vector<cv::Point>> contours = check_contours(lightFrame);
        //检测灯条 
        detect_light(contours,l);
        //匹配灯条
        match_light( frame, l, a );
        //匹配装甲板
        match_armour(l,a);
        //绘制
        draw_armor(frame,l,a);
        cv::imshow("armor",frame);
        //解pnp
        PnpSlover pnp;
        pnp.calculate_pnp( a );
        a.four_point.clear();
        }
        key=waitKey(1);
        if (key==27) {
            cam.close_cam();
            break;
        }
        frame.release();
    }
    return;
}