// Face Detection + Mask Alert System
#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include <vector>
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
    vector<double> fps_values;
    int total_faces_detected = 0;

    while (true) {
        cap >> frame;
        auto start = high_resolution_clock::now();
        // FIX 3: Check if frame is empty before processing
        if (frame.empty()) {
           
            cout << "Empty frame received! Skipping..." << endl;
            continue;
        }

        cvtColor(frame, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, gray);

        vector<Rect> faces;
        face_cascade.detectMultiScale(gray, faces, 1.3, 5);
        auto end = high_resolution_clock::now();

    double time_taken = duration<double>(end - start).count();

    total_time += time_taken;
    frame_count++;

    double fps = frame_count / total_time;
    fps_values.push_back(fps);
    total_faces_detected += faces.size();

        for (size_t i = 0; i < faces.size(); i++) {
        rectangle(frame, faces[i], Scalar(255, 0, 0), 2);

        putText(frame, "No Mask!",
                Point(faces[i].x, faces[i].y - 10),
                FONT_HERSHEY_SIMPLEX, 0.8,
                Scalar(0, 0, 255), 2);
        }

        putText(frame, "Faces: " + to_string(faces.size()),
                Point(10, 30),
                FONT_HERSHEY_SIMPLEX, 1,
                Scalar(0, 255, 0), 2);

        putText(frame, "Camera Index: " + to_string(cameraIndex),
                Point(10, 60),
                FONT_HERSHEY_SIMPLEX, 0.6,
                Scalar(255, 255, 0), 1);

        putText(frame, "FPS: " + to_string((int)fps),
                Point(10, 80),
                FONT_HERSHEY_SIMPLEX, 1,
                Scalar(255, 0, 0), 2);

        imshow("Face Detection", frame);


        if (waitKey(30) == 27) break;
    }

    double avg_fps = (total_time > 0) ? frame_count / total_time : 0;
    double detection_rate = (frame_count > 0) ? (double)total_faces_detected / frame_count : 0;

    cout << "\n===== EVALUATION METRICS =====" << endl;
    cout << "Average FPS: " << avg_fps << endl;
    cout << "Total Faces Detected: " << total_faces_detected << endl;
    cout << "Detection Rate (faces/frame): " << detection_rate << endl;

    Mat graph = Mat::zeros(400, 600, CV_8UC3);

    line(graph, Point(50, 350), Point(550, 350), Scalar(255, 255, 255), 2);
    line(graph, Point(50, 50), Point(50, 350), Scalar(255, 255, 255), 2);

    putText(graph, "FPS Graph",
            Point(200, 30),
            FONT_HERSHEY_SIMPLEX, 1,
            Scalar(255, 255, 255), 2);

    for (int i = 1; i < fps_values.size(); i++) {
        line(graph,
            Point(50 + (i-1)*5, 350 - fps_values[i-1]*5),
            Point(50 + i*5, 350 - fps_values[i]*5),
            Scalar(0, 255, 0), 2);
    }

    imshow("FPS Graph", graph);
    waitKey(0);

    cap.release();
    destroyAllWindows();
    cout << "Program exited cleanly." << endl;
    system("pause");
    return 0;
}
     

   
