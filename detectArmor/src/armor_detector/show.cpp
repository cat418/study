#include "detect.h"

//展示
void Armor_detector::show(std::string name,Armour a,Light l,int limit) {
    m_cap.open(name);
    if(!m_cap.isOpened()) {
        std::cout<<"error"<<std::endl;
        return;
    }
    while(true) {
        l.light_rect.clear();
        a.two_Light.clear();

        //读取图像
        cv::Mat frame=read_frame().clone();
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
        }
        int fps=m_cap.get(cv::CAP_PROP_FPS);
        if (fps <= 0) {
        fps = 30;  // 设置默认的帧率
        }
        cv::waitKey(1000/fps);
        frame.release();
    }
    return;
}