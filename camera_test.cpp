#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the default camera. On Windows, adding cv::CAP_DSHOW often helps.
    cv::VideoCapture cap(0); 

    // 1. Check if camera opened successfully
    if (!cap.isOpened()) {
        std::cerr << "ERROR: Blank frame grabbed or camera not connected." << std::endl;
        return -1;
    }

    cv::Mat frame;
    cv::namedWindow("My Camera", cv::WINDOW_AUTOSIZE);

    std::cout << "Camera opened successfully! Press 'q' to quit." << std::endl;

    while (true) {
        cap >> frame; // Capture a new frame
        
        if (frame.empty()) {
            std::cerr << "ERROR: Frame is empty." << std::endl;
            break;
        }

        cv::imshow("My Camera", frame);

        // 2. The crucial waitKey function
        if (cv::waitKey(1) == 'q') {
            break; // Exit if 'q' is pressed
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}