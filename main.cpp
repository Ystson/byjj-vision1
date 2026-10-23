#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap("/home/yst/Code/rm_vision/装甲板视频.avi"); 
    if (!cap.isOpened()) {
        cout << "视频打不开！检查路径对不对。" << endl;
        return -1;
    }

    Mat frame, hsv, mask;
    double fps = cap.get(CAP_PROP_FPS);
    int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
    
    VideoWriter writer("output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, Size(frame_width, frame_height));
    if (!writer.isOpened()) {
        cout << "无法创建视频文件！" << endl;
        return -1;
    }
    while (true) {
        cap >> frame; 
        if (frame.empty()) break; 
        cvtColor(frame, hsv, COLOR_BGR2HSV);
        Mat mask1, mask2;
        inRange(hsv, Scalar(0, 100, 100), Scalar(10, 255, 255), mask1);
        inRange(hsv, Scalar(160, 100, 100), Scalar(180, 255, 255), mask2);
        mask = mask1 | mask2; 
        vector<vector<Point>> contours; 
        findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
         for (size_t i = 0; i < contours.size(); i++) {
            RotatedRect rect = minAreaRect(contours[i]); 
            

            float width = rect.size.width;
            float height = rect.size.height;
            float aspect_ratio = max(width, height) / min(width, height); 

            if (contourArea(contours[i]) > 15 && aspect_ratio > 2.5) {
                
        
                Point2f vertices[4];
                rect.points(vertices);
                
               
                for (int j = 0; j < 4; j++) {
                    line(frame, vertices[j], vertices[(j + 1) % 4], Scalar(0, 255, 0), 2);
                }
            }
        }

      
        imshow("RM Vision Result", frame);
         writer << frame; 
        if (waitKey(30) == 27) break; 
    }

    return 0;
}