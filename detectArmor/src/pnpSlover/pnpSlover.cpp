#include "detect.h"
#include "pnpslover.h"

//世界坐标系和相机坐标系 z
//设置相机内参矩阵 畸变系数
void PnpSlover::calculate_pnp(Armour a) {
    m_matrix = (cv::Mat_<double>(3,3) <<
    1809.870863937357, 0, 690.2243899941344,
    0, 1812.98436546181, 562.730599006955,
    0, 0, 1
    );
    m_distCoeffs = (cv::Mat_<double>(1,5) <<-0.06356538390336125, 0.03903999928160801, -0.001395636011335281, -0.001940042987071293, 0.2630557748237058);
    float small_armro_half_x = a.m_width / 2 ,  small_armro_half_y = a.m_height / 2 ;
    m_small_armor_point3d.push_back(cv::Point3f(-0, small_armro_half_x, small_armro_half_y));   //左上
    m_small_armor_point3d.push_back(cv::Point3f(-0, -small_armro_half_x, -small_armro_half_y));   // 左下
    m_small_armor_point3d.push_back(cv::Point3f(-0,  small_armro_half_x, -small_armro_half_y));    // 右下
    m_small_armor_point3d.push_back(cv::Point3f(-0,  small_armro_half_x,  small_armro_half_y));   // 右上
    cv::Mat rvec;
    cv::Mat tvec;
    if( m_small_armor_point3d.size() == a.four_point.size() ) {
        cv::solvePnP( m_small_armor_point3d, a.four_point, m_matrix, m_distCoeffs, rvec, tvec, false, cv::SOLVEPNP_ITERATIVE);
        std::cout <<  "rvec = "<< rvec.at<double>(0,0)<<" ,"<< rvec.at<double>(1,0)<<" ,"<< rvec.at<double>(2,0)<<std::endl;
        std::cout << "tvec = "<< tvec.at<double>(0,0)<<" ,"<< tvec.at<double>(1,0)<<" ,"<< tvec.at<double>(2,0)<<std::endl;
    }
}