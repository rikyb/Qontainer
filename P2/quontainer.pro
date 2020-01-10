#-------------------------------------------------
#
# Project created by QtCreator 2018-12-14T10:18:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quontainer
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    articolo.cpp \
    apparecchio.cpp \
    printer.cpp \
    smartphone.cpp \
    computer.cpp

HEADERS  += mainwindow.h \
    articolo.h \
    apparecchio.h \
    printer.h \
    smartphone.h \
    computer.h
