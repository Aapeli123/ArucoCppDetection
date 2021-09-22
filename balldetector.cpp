#include "balldetector.h"
void detectFloorballs(cv::Mat data) {
    auto ksize = cv::Size(5,5);
    cv::namedWindow("example", cv::WINDOW_AUTOSIZE);
    cv::imshow("example", data);
    cv::Mat mask;
    
    cv::Mat out = data.clone(); 
    
    std::vector<float> neglowerB = {120, 45, 30};
    std::vector<float> neghigherB = {175, 255, 255};
    cv::GaussianBlur(data, data, ksize, 4);
    cv::GaussianBlur(data, data, ksize, 8);
    cv::convertScaleAbs(data, data, 0.5, 0);
    cv::imshow("example", data);
    cv::waitKey(0);
    cv::cvtColor(data, mask, cv::COLOR_BGR2HSV);
    cv::inRange(mask, neglowerB, neghigherB, mask);


    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    cv::drawContours(out, contours, -1, cv::Scalar(0, 0, 255), 2, 8, hierarchy);
    while(1) {
        cv::imshow("example", out);
        if(cv::waitKey(1) % 256 == 27) {
                break;
        }
    }
}

