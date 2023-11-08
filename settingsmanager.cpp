// settingsmanager.cpp
#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject* parent) : QObject(parent) {
    settings.beginGroup("MyAppSettings");
}

void SettingsManager::setFontColor(const QString& color) {
    settings.setValue("fontColor", color);
}

QString SettingsManager::getFontColor() {
    QString savedColor = settings.value("fontColor").toString();
    if (savedColor.isEmpty()) {
        // 저장된 설정이 없으면 기본값 "blue"를 반환
        savedColor = "blue";
    }
    return savedColor;
}

void SettingsManager::setColorCode(const QString& colorCode) {
    settings.setValue("colorCode", colorCode);
}

QString SettingsManager::getColorCode() {
    QString savedColorCode = settings.value("colorCode").toString();
    if (savedColorCode.isEmpty()) {
        // 저장된 설정이 없으면 기본값 "blue"를 반환
        savedColorCode = "0000FF";
    }
    return savedColorCode;
}