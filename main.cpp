#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QtDebug>
#include <QColor>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencvwidget.h"
#include "cameralistmodel.h"
#include "settingmanager.h"
using namespace cv;

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    CamObj camObj;
    engine.rootContext()->setContextProperty("camObj", &camObj);

    // 연결된 Cam 목록
    CameraListModel cameraListModel;

    // setting
    SettingManager settingManager;
    engine.rootContext()->setContextProperty("cameraListModel", &cameraListModel);
    engine.rootContext()->setContextProperty("settingManager", &settingManager);
    engine.load(QUrl(QStringLiteral("qrc:/qt/qml/processcam/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
