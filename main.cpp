#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/mat.hpp>

int main() {
    cv::namedWindow("videoCapture", cv::WINDOW_AUTOSIZE);
    auto capture = cv::VideoCapture(0);
    auto data = cv::Mat();
    
    bool succ = capture.read(data);
    if(!succ) {
        std::cout << "Something went wrong...\n";
        return 1;
    }
    cv::imshow("videoCapture", data);
}
