#-------------------------------------------------
#
# Project created by QtCreator 2015-04-08T19:30:10
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = hdf5reader
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

 LIBS += /usr/lib//x86_64-linux-gnu/libhdf5_cpp.so -lhdf5
