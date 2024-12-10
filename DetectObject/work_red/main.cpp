#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
using namespace cv;

// void mouseCallback(int event,int x,int y,int flags,void* param)
// {
//     if(event==EVENT_LBUTTONDOWN)
//     {
//         Mat* frame=reinterpret_cast<Mat*>(param);
//         Mat hsv;
//         cvtColor(*frame,hsv,COLOR_BGR2HSV);
//         Vec3b hsvValue=hsv.at<Vec3b>(Point(x,y));
//         cout<<"HSV:("<<(int)hsvValue[0]<<","<<(int)hsvValue[1]<<","<<(int)hsvValue[2]<<","<<")"<<endl;
//     }
// }

int main()
{
    VideoCapture cap("red.avi");
    if(!cap.isOpened())
    {
        cout<<"error"<<endl;
        return -1;
    } 

    Point2f lastPosition(0,0);//上一帧的中心位置 初始化为(0,0)
    float alpha = 1;//平滑因子

    while(1)
    {
        Mat frame;
        cap>>frame;
        if(frame.empty())
        {
            break;
        }


        Mat changeFrame;
        cvtColor(frame,changeFrame,COLOR_BGR2HSV);

        //定义红色阈值

        Scalar lower_red(0,10,10);
        Scalar upper_red(10,180,180);

        //创建掩膜
        Mat mask;
        //检测图像中像素值是否在指定的范围内
        //在阈值范围内的为白色，反之为黑色
        inRange(changeFrame,lower_red,upper_red,mask);

        //查找轮廓
        vector<vector<Point>> contours;
        //RETR_TREE: 检测所有轮廓，并重建轮廓之间的层次关系，形成一个树结构。
        //保留所有轮廓点，不进行压缩

        findContours(mask,contours,RETR_TREE,CHAIN_APPROX_NONE);

        vector<Vec4i> hierarchy;
        Point2f currentPosition;//当前位置

        //在原始图像上绘制轮廓
        for(const auto& contour : contours)
        {
           if(contourArea(contour)>2500)
            {
                Rect boundingBox=boundingRect(contour);
                rectangle(frame,boundingBox,Scalar(0,0,225),2,8,0);
                //计算矩形中心
                //tl左上角的坐标 br右下角的坐标
                currentPosition=(boundingBox.tl()+boundingBox.br())*0.5;
            }
        }

        //如果检测到目标，应用平滑
        if(!contours.empty())
        {
            //使用移动平均平滑目标位置
            //当前位置在结果中的加权贡献
            //上一位置在结果中的加权贡献
            Point2f smoothedPosition = alpha * currentPosition + (1-alpha) * lastPosition;
            lastPosition = smoothedPosition;

            //绘制平滑后的目标位置
            circle(frame,smoothedPosition,5,Scalar(0,0,225),-1);//绘制平滑位置
        }

        int fps=cap.get(CAP_PROP_FPS);
        int delay=1000/fps;
        imshow("Video",frame);
        if(waitKey(delay)=='q')
        {
            break;
        }
    }
    
    // Mat frame;
    // cap>>frame;
    // imshow("Video",frame);
    // setMouseCallback("Video",mouseCallback,&frame);
    
    // while(true)
    // {
    //     cap>>frame;
    //     if(frame.empty())
    //     {
    //         break;
    //     }

    //     imshow("Video",frame);
    //    waitKey(300);
    // }
    cap.release();
    // destroyAllWindows();
    waitKey(0);
    return 0;
}