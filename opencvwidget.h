#pragma once

#include <QtQuick>
#include <QQuickPaintedItem>
#include <QImage>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <QObject>
using namespace cv;

class CamObj : public QObject
{
    Q_OBJECT

public:
    explicit CamObj(QObject* parent = nullptr);

public slots:
    void showCam(int camNum, QString colorCode);
};

class ThreadedCamera {
public:
    ThreadedCamera(int source) {
        cap.open(source, cv::CAP_DSHOW);
        
        //codec = 0x47504A4D // MJPG
        //codec = 844715353.0 // YUY2
        double codec = 0x47504A4D;

        cap.set(CAP_PROP_FOURCC, codec);
        //cap.open("C:/Users/SYNERGY-USER/Downloads/abc/bear.mp4", cv::CAP_V4L2);
        cap.set(CAP_PROP_FPS, 30);
        cap.set(CAP_PROP_FRAME_WIDTH, 3840);
        cap.set(CAP_PROP_FRAME_HEIGHT, 2160);
        //std::cout << cap.get(CAP_PROP_FRAME_WIDTH) << std::endl;
        //std::cout << cap.get(CAP_PROP_FRAME_HEIGHT) << std::endl;

        status = false;
        frame = Mat();
    }

    Mat grabFrame() {
        if (cap.isOpened()) {
            status = cap.read(frame);
        }

        if (status) {
            return frame;
        }
        return Mat();
    }

    void stop() {
        cap.release();
    }

private:
    VideoCapture cap;
    bool status;
    Mat frame;
};

// 원본 카메라 화면에 이미지 덧씌우기 작업(병렬처리)
class  ProcessSubRegion : public ParallelLoopBody {
private:
    Mat& frame;
    Mat& fgmask;
    int squareSize;
    Scalar fontColor;
public:
    ProcessSubRegion(Mat& _frame, Mat& _fgmask, int _squareSize, Scalar _fontColor)
        : frame(_frame), fgmask(_fgmask), squareSize(_squareSize), fontColor(_fontColor) {}

    void operator()(const cv::Range& range) const {
        for (int y = range.start * squareSize; y < range.end * squareSize; y += squareSize) {
            for (int x = 0; x < frame.cols; x += squareSize) {
                Mat subRegion = fgmask(cv::Rect(x, y, squareSize, squareSize));
                if (cv::countNonZero(subRegion) == 0) {
                    Vec3b color = frame.at<Vec3b>(y + (squareSize / 2), x + (squareSize / 2));        // 원본이미지 해당 위치의 색상 추출

                    cv::Rect rect(x, y, squareSize, squareSize);        // 사각형 사이즈
                    cv::rectangle(frame, rect, Scalar(0, 0, 0), -1);    // 사각형 그리기

                    char hexColor[8];
                    std::snprintf(hexColor, sizeof hexColor, "%02x%02x%02x", color[2], color[1], color[0]);

                    putText(frame(rect), hexColor, Point(1, (squareSize / 2)), FONT_HERSHEY_SIMPLEX, 0.3, fontColor, 1, LINE_AA);   // 실시간 변화하는 원본 색상코드 사각형 중앙에 출력
                    // 영역 회전 (예: 90도 회전)
                    double angle = 270;
                    cv::Point center((squareSize / 2), (squareSize / 2));
                    cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);
                    cv::warpAffine(frame(rect), frame(rect), rotationMatrix, frame(rect).size());
                }
            }
        }
    }
};
