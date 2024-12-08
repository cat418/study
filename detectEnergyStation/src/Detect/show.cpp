#include "detect.h"

void Detect::show(  std::string name, DetectR &R) {
    Detect detect;
    m_cap.open( name );
    if( !m_cap.isOpened() ) {
        throw std::runtime_error( "open video false" );
    }
    while( true ) {
        //读取图像
        cv::Mat frame = readFrame();
        //预处理
        cv::Mat deal_frame = dealFrame( frame );
        //检查轮廓
        checkContours( deal_frame, detect );
        //筛选R轮廓
        R.findR( detect, R );
        //绘制
        R.drawR( frame, deal_frame, R );

        R.m_contours.clear();
        detect.m_allContours.clear();
        detect.m_hierarchy.clear();
        cv::imshow( "result", frame );
        m_FPS = m_cap.get( cv::CAP_PROP_FPS );
        float delay = 1000/m_FPS;
        cv::waitKey( delay );
    }
}