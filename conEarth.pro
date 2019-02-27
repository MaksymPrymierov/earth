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
    src/QBuilding/QBuilding.cpp \
    src/QBuilding/QCleaningStation.cpp \
    src/QBuilding/QEnergyStation.cpp \
    src/QBuilding/QFarm.cpp \
    src/QBuilding/QLaboratory.cpp \
    src/QBuilding/QMine.cpp \
    src/QConWidgets/QButtonsPanel.cpp \
    src/QConWidgets/QGameMainWindow.cpp \
    src/QConWidgets/QGameScreen.cpp \
    src/QConWidgets/QMainMenu.cpp \
    src/QConWidgets/QTextPanel.cpp \
    src/main.cpp \
    src/QWorld.cpp \
    src/QBuilding/QStock.cpp


HEADERS += \
    headers/QBuilding/QBuilding.h \
    headers/QBuilding/QCleaningStation.h \
    headers/QBuilding/QEnergyStation.h \
    headers/QBuilding/QFarm.h \
    headers/QBuilding/QLaboratory.h \
    headers/QBuilding/QMine.h \
    headers/QConWidgets/QButtonsPanel.h \
    headers/QConWidgets/QGameMainWindow.h \
    headers/QConWidgets/QGameScreen.h \
    headers/QConWidgets/QMainMenu.h \
    headers/QWorld.h \
    headers/QConWidgets/QTextPanel.h \
    headers/QBuilding/QStock.h




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
    resources/images/mainmenu.png \
    LICENSE

