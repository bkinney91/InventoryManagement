#-------------------------------------------------
#
# Project created by QtCreator 2015-09-22T16:36:11
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InventoryManagement
TEMPLATE = app


SOURCES += main.cpp\
        homepage.cpp \
    loginDialog.cpp \
    dashboard.cpp \
    DashboardDAL.cpp \
    part.cpp

HEADERS  += homepage.h \
    loginDialog.h \
    dashboard.h \
    DashboardDAL.h \
    part.h

FORMS    += homepage.ui \
    loginDialog.ui

RESOURCES +=
