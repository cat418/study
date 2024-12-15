#include "detect.h"
#include "pnpslover.h"

//世界坐标系和相机坐标系 z向前 ,x向右 ,y向下
//设置相机内参矩阵 畸变系数
void PnpSlover::calculate_pnp(Armour &a, Light &l) {
    m_matrix = (cv::Mat_<double>(3,3) <<
    1809.870863937357, 0, 690.2243899941344,
    0, 1812.98436546181, 562.730599006955,
    0, 0, 1
    );
    m_distCoeffs = (cv::Mat_<double>(1,5) <<-0.06356538390336125, 0.03903999928160801, -0.001395636011335281, -0.001940042987071293, 0.2630557748237058);
    
    // m_matrix = (cv::Mat_<double>(3,3) <<
    // 1814.304470709766, 0, 680.0866838997997,
    // 0, 1816.46254639905, 572.3860870746728,
    // 0, 0, 1
    // );
    // m_distCoeffs = (cv::Mat_<double>(1,5) <<-0.1140280192150111, 0.6440347079155343, 0.0002982650615947499, -0.002297783671074355, -1.876992654445899);

    float small_armro_half_x = a.m_width / 2.0 / 100.0 ,  small_light_half_y = l.m_height / 2.0 / 100.0;
    m_small_armor_point3d.push_back(cv::Point3f(-0, small_armro_half_x, small_light_half_y));   //左上
    m_small_armor_point3d.push_back(cv::Point3f(-0,  small_armro_half_x, -small_light_half_y));   //左下
    m_small_armor_point3d.push_back(cv::Point3f(-0,  small_armro_half_x,  small_light_half_y));   //右下
    m_small_armor_point3d.push_back(cv::Point3f(-0, -small_armro_half_x, -small_light_half_y));   //右上

    cv::Mat rvec = cv::Mat::zeros(3, 1, CV_64F);
    cv::Mat tvec = cv::Mat::zeros(3, 1, CV_64F);
    if( m_small_armor_point3d.size() == a.four_point.size() && a.four_point.size() == 4 ) {
        cv::solvePnP( m_small_armor_point3d, a.four_point, m_matrix, m_distCoeffs, rvec, tvec, false, cv::SOLVEPNP_ITERATIVE);
        // std::cout <<  "rvec = "<< rvec.at<double>(0,0)<<" ,"<< rvec.at<double>(1,0)<<" ,"<< rvec.at<double>(2,0)<<std::endl;
        // std::cout << "tvec = "<< tvec.at<double>(0,0)<<" ,"<< tvec.at<double>(1,0)<<" ,"<< tvec.at<double>(2,0)<<std::endl;
        double distance = cv::norm(tvec);
        std::cout << "distance " << "=" << " " << distance << std::endl;
    } 
}