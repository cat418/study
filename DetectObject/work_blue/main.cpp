#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace cv;

// //鼠标回调函数
// void mouseCallback(int event,int x,int y,int,void* param)
// {
//   if(event==EVENT_LBUTTONDOWN)//点击鼠标左键
//   {
//     Mat* frame=reinterpret_cast<Mat*>(param);
//     Vec3b bgr=frame->at<Vec3b>(Point(x,y));//获取BGR值
//     cout<<"bgr:("<<(int)bgr[0]<<","<<(int)bgr[1]<<","<<(int)bgr[2]<<")"<<endl;
//     //转化为HSV
//     Mat hsv;
//     cvtColor(*frame,hsv,COLOR_BGR2HSV);
//     Vec3b hsvValue=hsv.at<Vec3b>(Point(x,y));
//     cout<<"HSV:("<<(int)hsvValue[0]<<","<<(int)hsvValue[1]<<","<<(int)hsvValue[2]<<")"<<endl;
//   }
// }

int main(int argc, char** argv) 
{
  VideoCapture work("blue.avi");
  if(!work.isOpened())
  {
    cout<<"error"<<endl;
    return -1;
  }

  Point2f lastPosition(0,0);
  float alpha=1;

  // Mat findFrame;
  // work>>findFrame;//读取第一帧
  // imshow("Video",findFrame);
  // setMouseCallback("Video",mouseCallback,&findFrame);

  // while(true)
  // {
  //   work>>findFrame;//持续读取每一帧
  //   if(findFrame.empty())
  //   {
  //     break;
  //   }

  //   imshow("Video",findFrame);
  //   if(waitKey(30)>=0) break;
  // }

  while(1)
  {
    
    Mat frame;
    work>>frame;//读取每一帧
    if(frame.empty())
    {
      break;
    }

    //转换颜色空间
    Mat changeWork;
    cvtColor(frame,changeWork,COLOR_BGR2HSV);
   
    //定义蓝色阙值
    Scalar lower_blue(103,121,55);
    Scalar upper_blue(108,179,242);
    //创建掩膜
    Mat mask;
    inRange(changeWork,lower_blue,upper_blue,mask);
    
    //查找轮廓
    vector<vector<Point>> contours;
    findContours(mask,contours,RETR_TREE,CHAIN_APPROX_NONE);

    Point2f currentPosition;
    //在原始图像上绘制轮廓
    for( const auto& contour : contours ) {
      if(contourArea(contour)>2500) {
        Rect boundingBox=boundingRect(contour);
        rectangle(frame,boundingBox,Scalar(200,55,0),2);
        currentPosition=(boundingBox.tl()+boundingBox.br())*0.5;
      }
    }

    if(!contours.empty()) {
      Point2f smoothedPosition = alpha * currentPosition + (1-alpha) * lastPosition;
      lastPosition=smoothedPosition;
      circle(frame,smoothedPosition,5,Scalar(225,0,0),-1);
    }
    int fps = work.get(CAP_PROP_FPS); 
    //按照原速度播放
    int delay = 1000 / fps;  
    imshow("Video",frame);
    //按'q'键退出
    if(waitKey(delay)=='q')
    {
        break;
    }
  }
  //释放资源
  work.release();
  // work.release();
  // destroyAllWindows();
  waitKey(0);
  return 0;
}