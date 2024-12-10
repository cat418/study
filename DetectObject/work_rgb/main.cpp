#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// void mouseCallback(int event,int x,int y,int flags,void* param)
// {
//     if(event==EVENT_LBUTTONDOWN)
//     {
//         Mat *frame=reinterpret_cast<Mat *>(param);
//         Mat hsv;
//         cvtColor(*frame,hsv,COLOR_BGR2HSV);
//         Vec3b hsvValue=hsv.at<Vec3b>(Point(x,y));
//         cout<<"HSV:("<<(int)hsvValue[0]<<","<<(int)hsvValue[1]<<","<<(int)hsvValue[2]<<")"<<endl;;
//     }
// }

int main()
{
    VideoCapture rgb("rgb.avi");
    if(!rgb.isOpened())
    {
        cout<<"error"<<endl;
        return -1;
    }

    //上一帧的中心位置 初始化为(0,0)
    Point2f b_lastPosition(0,0);
    Point2f r_lastPosition(0,0);
    Point2f g_lastPosition(0,0);
    float alpha=1;

    while(1)
    {
        Mat frame;
        rgb>>frame;
        if(frame.empty())
        {
            break;
        }

        Mat changeFrame;
        cvtColor(frame,changeFrame,COLOR_BGR2HSV);

        //定义蓝色阈值
        Scalar lower_blue(100,115,35);
        Scalar upper_blue(108,183,248);
        //定义红色阈值
        Scalar lower_red(2,10,10);
        Scalar upper_red(10,180,184);
        //定义绿色阈值
        Scalar lower_green(46,66,34);
        Scalar upper_green(81,128,126);

        //创建掩膜
        Mat b_mask;
        inRange(changeFrame,lower_blue,upper_blue,b_mask);
        Mat g_mask;
        inRange(changeFrame,lower_green,upper_green,g_mask);
        Mat r_mask;
        inRange(changeFrame,lower_red,upper_red,r_mask);

        //使用Canny边缘检测
        Mat b_edges;
        Canny(b_mask,b_edges,100,200);
        Mat r_edges;
        Canny(r_mask,r_edges,100,200);
        Mat g_edges;
        Canny(g_mask,g_edges,100,200);

        //查找轮廓
        vector<vector<Point>> r_contours;
        vector<vector<Point>> g_contours;
        vector<vector<Point>> b_contours;
        findContours(b_mask,b_contours,RETR_TREE,CHAIN_APPROX_NONE);
        findContours(r_mask,r_contours,RETR_TREE,CHAIN_APPROX_NONE);
        findContours(g_mask,g_contours,RETR_TREE,CHAIN_APPROX_NONE);

        Point2f r_currentPosition;//当前位置
        Point2f b_currentPosition;
        Point2f g_currentPosition;
        //绘制轮廓
        for(const auto& r_contour : r_contours)
        {
            if(contourArea(r_contour)>2500)
            {
                Rect r_boundingBox=boundingRect(r_contour);
                rectangle(frame,r_boundingBox,Scalar(0,0,225),2,8,0);
                //计算矩形中心
                r_currentPosition=(r_boundingBox.tl()+r_boundingBox.br())*0.5;
            }
        }

        for(const auto& b_contour : b_contours)
        {
            if(contourArea(b_contour)>2500)
            {
            Rect b_boundingBox=boundingRect(b_contour);
            rectangle(frame,b_boundingBox,Scalar(225,0,0),2,8,0);
            //计算矩形中心
            b_currentPosition=(b_boundingBox.tl()+b_boundingBox.br())*0.5;
            }
        }

        for(const auto& g_contour : g_contours)
        {
            if(contourArea(g_contour)>2500)
            {
            Rect g_boundingBox = boundingRect(g_contour);
            rectangle(frame,g_boundingBox,Scalar(0,255,0),2,8,0);
            //计算矩形中心
            g_currentPosition=(g_boundingBox.tl()+g_boundingBox.br())*0.5;
            }
        }
        //如果检测到目标，应用平滑
        if(!r_contours.empty())
        {
            //使用移动平均平滑目标位置
            Point2f r_smoothedPosition = alpha * r_currentPosition + (1-alpha) * r_lastPosition;
            r_lastPosition=r_smoothedPosition;
            //绘制平滑后的目标位置
            circle(frame,r_smoothedPosition,5,Scalar(0,0,225),-1);
        }
        if(!b_contours.empty())
        {
            Point2f b_smoothedPosition = alpha *b_currentPosition + (1-alpha)*b_lastPosition;
            b_lastPosition=b_smoothedPosition;
            //图像被绘制在frame上 b_smoothedPosition是圆心的坐标 5是半径 -1代表实心
            circle(frame,b_smoothedPosition,5,Scalar(225,0,0),-1);
        }
        if(!g_contours.empty())
        {
            Point2f g_smoothedPosition=alpha *g_currentPosition + (1-alpha) * g_lastPosition;
            g_lastPosition=g_smoothedPosition;
            circle(frame,g_lastPosition,5,Scalar(0,225,0),-1);
        }
        int fps=rgb.get(CAP_PROP_FPS);
        int delay=1000/fps;
        imshow("Vedio",frame);
        if(waitKey(delay)=='q')
        {
            break;
        }

    }
    // Mat frame;
    // rgb>>frame;
    // imshow("Video",frame);
    // setMouseCallback("Video",mouseCallback,&frame);

    // while(true)
    // {
    //     rgb>>frame;
    //     if(frame.empty())
    //     {
    //         break;
    //     }

    //     imshow("Video",frame);
    //     waitKey(100);
    // }
    rgb.release();
    waitKey(0);
    return 0;
}