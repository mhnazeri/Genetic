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
    qcustomplot.cpp \
    random_generator.cpp \
    sphere.cpp

HEADERS  += interface.h \
    mindistance.h \
    qcustomplot.h \
    random_generator.h \
    sphere.h

FORMS    += interface.ui
