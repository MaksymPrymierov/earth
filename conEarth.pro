#-------------------------------------------------
#
# Project created by QtCreator 2019-01-26T06:03:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = conEarth
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
    src/building/building.cpp \
    src/building/cleaningstation.cpp \
    src/building/energystation.cpp \
    src/building/farm.cpp \
    src/building/laboratory.cpp \
    src/building/mine.cpp \
    src/conWidget/buttonspanel.cpp \
    src/conWidget/gamescreen.cpp \
    src/conWidget/mainmenu.cpp \
    src/conWidget/mainwindow.cpp \
    src/main.cpp \
    src/world.cpp \
    src/conWidget/textpanel.cpp


HEADERS += \
    headers/building/building.h \
    headers/building/cleaningstation.h \
    headers/building/energystation.h \
    headers/building/farm.h \
    headers/building/laboratory.h \
    headers/building/mine.h \
    headers/conWidget/buttonspanel.h \
    headers/conWidget/gamescreen.h \
    headers/conWidget/mainmenu.h \
    headers/conWidget/mainwindow.h \
    headers/world.h \
    headers/conWidget/textpanel.h



FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    conEarth.pro

RESOURCES += \
    resources/images/images.qrc


DISTFILES += \
    resources/images/mainmenu.png

