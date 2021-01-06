#include <csignal>

#include <opencv2/opencv.hpp>

#include "GxCamera.hpp"

using std::cout;
using std::cerr;
using std::endl;

using cv::Mat;
using cv::imshow;
using cv::waitKey;

using GxCamera::Camera;

namespace {
    const double kExposureTime = 8000.0;
    const double kFrameRate = 120.0;

    // c-style string serial number for code compatibility
    // char left_cam_serial_num[] = "KE0200080465";
    // char right_cam_serial_num[] = "KE0200080462";

    bool stop_flag = false;
}

void SigintHandler(int sig) {
    stop_flag = true;
    cout << "SIGINT received, exiting" << endl;
}

int main(int argc, char const *argv[]){
    GX_STATUS status;

    Camera cam;
    status = cam.CameraInit();
    if(status != GX_STATUS_SUCCESS){
        cerr << "CameraInit fail" << endl;
        return EXIT_FAILURE;
    }

    status = cam.SetExposureTime(kExposureTime);
    if(status != GX_STATUS_SUCCESS){
        cerr << "CameraInit fail" << endl;
        return EXIT_FAILURE;
    }

    status = cam.SetFrameRate(kFrameRate);
    if(status != GX_STATUS_SUCCESS){
        cerr << "CameraInit fail" << endl;
        return EXIT_FAILURE;
    }

    status = cam.CameraStreamOn();
    if(status != GX_STATUS_SUCCESS){
        cerr << "CameraInit fail" << endl;
        return EXIT_FAILURE;
    }

    signal(SIGINT, SigintHandler);
    Mat img;
    while (!stop_flag){
        cam.GetLatestColorImg(img);
        imshow("test", img);
        waitKey(1);
    }

    cam.CameraStreamOff();
    cam.CameraClose();
    
    return EXIT_SUCCESS;
}
