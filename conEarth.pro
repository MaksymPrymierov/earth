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
    src/QConWidgets/QGameMainWindow.cpp \
    src/QConWidgets/QGameScreen.cpp \
    src/QConWidgets/QMainMenu.cpp \
    src/QConWidgets/QTextPanel.cpp \
    src/main.cpp \
    src/QConResources.cpp \
    src/Building/Building.cpp \
    src/Building/CleaningStation.cpp \
    src/Building/EnergyStation.cpp \
    src/Building/Farm.cpp \
    src/Building/Laboratory.cpp \
    src/Building/Mine.cpp \
    src/Building/Stock.cpp \
    src/QConWidgets/QButtonsPanel/QButtonsPanel.cpp \
    src/QConWidgets/QButtonsPanel/QMainMenuPanel.cpp \
    src/QConWidgets/QButtonsPanel/QActionPanel.cpp \
    src/QConWidgets/QButtonsPanel/QBuildPanel.cpp \
    src/QConWidgets/QButtonsPanel/QDestroyPanel.cpp \
    src/QConWidgets/QButtonsPanel/QSciencePanel.cpp \
    src/World/Science.cpp \
    src/World/World.cpp \
    src/World/WorldEvent.cpp



HEADERS += \
    headers/QConWidgets/QGameMainWindow.h \
    headers/QConWidgets/QGameScreen.h \
    headers/QConWidgets/QMainMenu.h \
    headers/QConWidgets/QTextPanel.h \
    headers/QConResources.h \
    headers/Building/Building.h \
    headers/Building/CleaningStation.h \
    headers/Building/EnergyStation.h \
    headers/Building/Farm.h \
    headers/Building/Laboratory.h \
    headers/Building/Mine.h \
    headers/Building/Stock.h \
    headers/QConWidgets/QButtonsPanel/QButtonsPanel.h \
    headers/QConWidgets/QButtonsPanel/QMainMenuPanel.h \
    headers/QConWidgets/QButtonsPanel/QActionPanel.h \
    headers/QConWidgets/QButtonsPanel/QBuildPanel.h \
    headers/QConWidgets/QButtonsPanel/QDestroyPanel.h \
    headers/QConWidgets/QButtonsPanel/QSciencePanel.h \
    headers/World/Science.h \
    headers/World/World.h \
    headers/World/WorldEvent.h \
    headers/World/WorldStats.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    conEarth.pro \
    conEarth.pro

RESOURCES += \
    resources/images/images.qrc



DISTFILES += \
    resources/images/mainMenuBackground-1368x768.png \
    resources/images/mainMenuBackground-2484x1200.png \
    LICENSE


