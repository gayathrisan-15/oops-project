// Face Detection + Mask Alert System
#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
using namespace std::chrono;

using namespace cv;
using namespace std;

int main() {
    // Load Haar Cascade model (use full path to be safe)
    CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_default.xml")) {
        cout << "Error loading cascade file!" << endl;
        cout << "Make sure haarcascade_frontalface_default.xml is in the same folder as face.exe" << endl;
        system("pause");
        return -1;
    }
    cout << "Cascade loaded successfully!" << endl;

    // FIX 1: Scan for available camera index
    int cameraIndex = -1;
    cout << "Scanning for available cameras..." << endl;
    for (int i = 0; i < 5; i++) {
        VideoCapture test(i);
        if (test.isOpened()) {
            cout << "Camera found at index: " << i << endl;
            cameraIndex = i;
            test.release();
            break;
        }
    }

    if (cameraIndex == -1) {
        cout << "No camera found! Please check your webcam connection." << endl;
        system("pause");
        return -1;
    }
    // Start webcam with detected index
    VideoCapture cap(cameraIndex);
    if (!cap.isOpened()) {
        cout << "Error opening camera at index " << cameraIndex << endl;
        system("pause");
        return -1;
    }

    // FIX 2: Set camera resolution explicitly
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    cout << "Camera opened successfully! Press ESC to quit." << endl;
    Mat frame, gray;
    int frame_count = 0;
    double total_time = 0;
    while (true) {
        cap >> frame;
        auto start = high_resolution_clock::now();
        // FIX 3: Check if frame is empty before processing
        if (frame.empty()) {
           
            cout << "Empty frame received! Skipping..." << endl;
            continue;
        }
        
        if (waitKey(30) == 27) break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
     

   
