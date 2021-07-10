#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/aruco.hpp>

#include <vector>

int main() {
    cv::namedWindow("frame", cv::WINDOW_AUTOSIZE);
    auto capture = cv::VideoCapture(0);
    auto data = cv::Mat();
    
    // Aruco data
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;

    // Aruco detection params
    auto parameters = cv::aruco::DetectorParameters::create();
    auto dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);


    while(true) {
        bool succ = capture.read(data);
        if(!succ) {
            std::cout << "Something went wrong...\n";
            return 1;
        }

        // Detect arucos from data:
        cv::aruco::detectMarkers(data, dictionary, markerCorners, ids, parameters);

        // Create a clone image that we can write the locations of arucos on:
        auto output = data.clone();
        cv::aruco::drawDetectedMarkers(output, markerCorners, ids);

        // Show image

        cv::imshow("frame", output);
        if(cv::waitKey(1) % 256 == 27) {
            break;
        }
        std::cout << "Found " << ids.size() << " arucos\n";
    };
    return 0;
}
