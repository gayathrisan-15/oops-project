# Face Detection + Mask Alert System (C++)

## Description
This project is a real-time face detection system implemented using C++ and OpenCV. It captures video from a webcam, detects human faces using a Haar Cascade classifier, and displays an alert message ("No Mask!") above each detected face. Additionally, the system counts the number of faces present in the frame and displays it on the screen. The mask detection in this project is simulated and intended to demonstrate alert functionality.

---

## File Structure

```bash
PROJ/
├── haarcascades/
│   └── haarcascade_frontalface_default.xml
├── face.cpp
├── face.exe
├── lk.cpp
```

### Project Overview
This project implements a real-time face detection system using the OpenCV library in C++. It detects human faces through a webcam, displays an alert message, and counts the number of faces in real time.

### Objectives
Detect faces using a webcam
Display alert message ("No Mask!")
Count number of faces detected
Demonstrate real-time computer vision using OpenCV

### Technologies Used
C++
OpenCV
Haar Cascade Classifier

### Key Concept
Haar Cascade Classifier
A pre-trained model used for detecting objects such as faces in images. It scans the image at multiple scales and identifies patterns that match human facial features.

### Features
Real-time face detection
Face count display
Alert system ("No Mask!" simulation)
Lightweight and fast execution

### Requirements
C++ Compiler (g++ / CodeBlocks / Visual Studio)
OpenCV installed
Webcam

### How to Run

1. Compile the code
 ```  
g++ face.cpp -o face `pkg-config --cflags --libs opencv4`
```
2. Run the program
  ``` 
 ./face.exe
 ```
4. Output
   
Webcam window opens

Faces are detected with rectangles

"No Mask!" alert is displayed

Number of faces is shown

### Conclusion

Successfully implemented real-time face detection using OpenCV

Integrated alert system to simulate mask detection

Added face counting feature for improved functionality

Achieved fast and efficient performance with low computational cost

Provides a foundation for future enhancements using deep learning


## Project Members:
1.Bonda Uma Venkata Varalakshmi - 25BCE2459

2.Gayathri Santhosh - 25BCE2428

3.Nandana C Sajith - 25BCE2440

4.T.Ananya rao - 25BCE2423

5.Jyosmita Saha - 25BCE2408

