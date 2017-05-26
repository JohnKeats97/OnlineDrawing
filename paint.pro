#-------------------------------------------------
#
# Project created by QtCreator 2015-09-24T19:55:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paint
TEMPLATE = app

CONFIG += C++11

SOURCES += main.cpp\
        paint.cpp \
    paintscene.cpp

HEADERS  += paint.h \
    paintscene.h \
    command.h \
    lock_guard.h

FORMS    += paint.ui
