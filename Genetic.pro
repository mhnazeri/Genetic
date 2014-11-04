#-------------------------------------------------
#
# Project created by QtCreator 2014-11-03T02:50:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Genetic
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        interface.cpp \
    mindistance.cpp \
    qcustomplot.cpp

HEADERS  += interface.h \
    mindistance.h \
    qcustomplot.h

FORMS    += interface.ui
