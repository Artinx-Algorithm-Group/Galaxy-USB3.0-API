# Galaxy USB3.0 API

API for Daheng Galaxy USB3.0 camera

## Author info

* Name: [Jing Yonglin](https://github.com/NERanger)
* Email: 11712605@mail.sustech.edu.cn / yonglinjing7@gmail.com

## Prerequisites

* [OpenCV](https://opencv.org/releases/)

> Sample verified on OpenCV 3.4.12.

* Galaxy USB3.0 driver library

> See attached release file

## Build and run sample program

First change the opencv path in CMakeLists.txt

```cmake
set(OpenCV_DIR /home/artinx001/3rdparty/opencv-3.4.12/build)
```

Then you can build and run the provided sample

```bash
# Build
mkdir build
cd build
cmake ..
make

# Run sample
cd ..
./bin/show_capture_image
```

## Features

* Continus capture
* Set camera exposure time
* Set camera frame rate
