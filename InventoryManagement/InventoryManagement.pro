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
    part.cpp \
    dashboarddal.cpp \
    sqlDAL.cpp \
    inventory.cpp \
    reports.cpp \
    administration.cpp

HEADERS  += homepage.h \
    loginDialog.h \
    dashboard.h \
    part.h \
    dashboarddal.h \
    sqlDAL.h \
    inventory.h \
    reports.h \
    administration.h

FORMS    += homepage.ui \
    loginDialog.ui

RESOURCES +=
