#include "opencvwidget.h"
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudabgsegm.hpp>
using namespace cv;
using namespace cv::cuda;

std::mutex m;
CamObj::CamObj(QObject* parent) : QObject(parent)
{
}

void CamObj::showCam(int camNum, QString colorCode)
{
    ThreadedCamera cam(camNum);
    cv::Ptr<cv::BackgroundSubtractorMOG2> fgbg = cv::createBackgroundSubtractorMOG2(1000, 256, false); // param -> history : 클수록 민감도 감소, varThreshold : 작을수록 작은 변화에도 반응, detectShadows: 그림자 검출 
    double FPS = 0;

    Mat fgmask;
    // 창 생성 및 전체 화면으로 설정
    cv::namedWindow("Real-time Video Processing", cv::WINDOW_NORMAL);
    cv::setWindowProperty("Real-time Video Processing", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);

    String colorStr = colorCode.toStdString();
    // R, G, B 채널 추출
    int r = stoi(colorStr.substr(0, 2), nullptr, 16);
    int g = stoi(colorStr.substr(2, 2), nullptr, 16);
    int b = stoi(colorStr.substr(4, 2), nullptr, 16);

    // Scalar로 변환
    cv::Scalar fontColor(b, g, r); // BGR 순서로 초기화합니다
    while (true) {
        Mat frame = cam.grabFrame();
        if (!frame.empty()) {
            double start_t = cv::getTickCount();
            fgbg->apply(frame, fgmask);
            int squareSize = 40;
            cv::Range range(0, frame.rows / squareSize);
            parallel_for_(range, ProcessSubRegion(frame, fgmask, squareSize, fontColor));
            double terminate_t = cv::getTickCount();
            FPS = cv::getTickFrequency() / (terminate_t - start_t);
            cv::putText(frame, std::to_string(int(round(FPS))), Point(0, 22), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);
            cv::imshow("Real-time Video Processing", frame);
        }
        int key = cv::waitKey(static_cast<int>(1000 / FPS));
        if (key == 113) { // 'q' 키의 ASCII 값은 113
            cam.stop();
            break;
        }
    }

    cv::destroyAllWindows();
}
