#-------------------------------------------------
#
# Project created by QtCreator 2019-07-13T10:52:14
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtInfoShowPro
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mymainwin.cpp \
    rollwin.cpp \
    picturewin.cpp \
    videowin.cpp \
    weathwin.cpp

HEADERS += \
        mymainwin.h \
    rollwin.h \
    picturewin.h \
    videowin.h \
    weathwin.h

FORMS += \
        mymainwin.ui \
    rollwin.ui \
    picturewin.ui \
    videowin.ui \
    weathwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/暴雪.png \
    images/暴雨.png \
    images/大暴雨.png \
    images/大雪.png \
    images/大雨.png \
    images/冻雨.png \
    images/多云.png \
    images/浮尘.png \
    images/雷阵雨.png \
    images/雷阵雨伴有冰雹.png \
    images/霾.png \
    images/强沙尘暴.png \
    images/晴.png \
    images/特大暴雨.png \
    images/雾.png \
    images/小雪.png \
    images/小雨.png \
    images/扬沙.png \
    images/阴.png \
    images/雨夹雪.png \
    images/阵雪.png \
    images/阵雨.png \
    images/中雪.png \
    images/中雨.png

RESOURCES += \
    res.qrc
