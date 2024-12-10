#include <opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;//声明使用opencv4.1的命名空间


int main(int argc,char** argv)
{
   VideoCapture work("green.avi");
    if(!work.isOpened())
    {
        cout<<"error"<<endl;
        return -1;
    }

    Mat frame;
    work>>frame;
    if(frame.empty())
    {
        cout<<"error"<<endl;
        return -1;
    }


    Point2f lastPosition(0,0);//上一帧的中心位置 初始化为(0,0)
    float alpha = 0.5;//平滑因子


    while(true)
    {
        Mat frame;
        work>>frame;
        if(frame.empty())
        {
            break;
        }

        Mat changeFrame;
        cvtColor(frame,changeFrame,COLOR_BGR2HSV);

        //定义绿色阈值

        Scalar lower_green(55,74,34);
        Scalar upper_green(78,134,144);

        //创建掩膜
        Mat mask;
        inRange(changeFrame,lower_green,upper_green,mask);

        //去噪声与二值化
        Mat canny;
        //边缘检测
        Canny(mask,canny,80,160,3,false);
        //膨胀运算将细小缝隙填满
        Mat kernal=getStructuringElement(0,Size(3,3));
        dilate(canny,canny,kernal);
        //轮廓的发现与检测
        //hierarchy 存储每个轮廓的父子关系和轮廓的类型信息
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(canny,contours,hierarchy,0,4,Point());

        Point2f currentPosition;
        //寻找轮廓的外接矩形
        for(const auto& contour : contours)
        {
            if(contourArea(contour)>2500)
            {
            //最大外接矩形
            Rect rect=boundingRect(contour);
            //2边框的厚度 8边框的类型
            rectangle(frame,rect,Scalar(0,225,0),2,8,0);

            //计算矩形的中心
            currentPosition=(rect.tl()+rect.br())* 0.5;
            }
        }
        //如果检测到目标应用平滑
        if(!contours.empty())
        {
            Point2f smoothedPosition = alpha *currentPosition+(1-alpha)* lastPosition;
            lastPosition=smoothedPosition;

            circle(frame,smoothedPosition,5,Scalar(0,225,0),-1);
        }
    
        int fps=work.get(CAP_PROP_FPS);
        int delay=1000/fps;
        imshow("Vedio",frame);
        if(waitKey(delay)=='q')
        {
            break;
        }
    }
    work.release();
    waitKey(0);
    return 0;    
}