#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T13:38:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaskTrackingSystem
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
        mainwindow.cpp \
    Model/Project.cpp \
    Model/Task.cpp \
    Model/User.cpp \
    Service/Service.cpp \
    DAO/UserDao.cpp \
    DAO/taskdao.cpp \
    DAO/projectdao.cpp \
    DAO/dbConnector.cpp \
    DAO/dao.cpp \
    addTaskWindow.cpp

HEADERS += \
    Model/model.h \    
    DAO/UserDao.h \
    DAO/UserDao.h \
    Service/Service.h \
    mainwindow.h \
    DAO/taskdao.h \
    DAO/projectdao.h \
    DAO/dbConnector.h \
    DAO/dao.h \
    addTaskWindow.h


FORMS += \
        mainwindow.ui \
    addTaskWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
