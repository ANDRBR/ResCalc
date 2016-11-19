#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T17:38:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ResCalc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    resval.cpp \
    colorChanged.cpp

HEADERS  += mainwindow.h \
    resval.h

FORMS    += ResCalc.ui

DISTFILES += \
    Changelog.txt \
    .gitattributes \
    .gitignore \
    README.md
