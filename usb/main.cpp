#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap( 0, cv::CAP_V4L2);
    if( !cap.isOpened() ) {
        cout << "error" << endl;
    }
    cap.set( CAP_PROP_FOURCC, VideoWriter::fourcc('M','J','P','G'));
    // 设置分辨率为 1280x960
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 960);
    // 设置帧率为 30 FPS
    cap.set(cv::CAP_PROP_FPS, 30);

    Mat frame;
    while (true) {
        cap >> frame; // 读取一帧画面
        if (frame.empty()) {
            cout << "Error: Frame capture failed" << endl;
            break;
        }

        imshow("USB Camera", frame); // 显示画面

        // 按下 'q' 键退出
        if (waitKey(1) == 'q') {
            break;
        }
    }

    cap.release(); // 释放摄像头
    destroyAllWindows(); // 关闭所有窗口

    return 0;
}