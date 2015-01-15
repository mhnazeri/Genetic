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
    sphere.cpp \
<<<<<<< HEAD
    kmeans.cpp \
    G1.cpp
=======
    banchmark1.cpp \
    kmeans.cpp \
    G2.cpp
>>>>>>> 1c400bd7f6745a854324017a43b74a22563eac52

HEADERS  += interface.h \
    mindistance.h \
    qcustomplot.h \
    random_generator.h \
    sphere.h \
<<<<<<< HEAD
    kmeans.h \
    G1.h
=======
    banchmark1.h \
    kmeans.h \
    G2.h
>>>>>>> 1c400bd7f6745a854324017a43b74a22563eac52

FORMS    += interface.ui
