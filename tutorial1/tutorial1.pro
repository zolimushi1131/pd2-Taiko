#-------------------------------------------------
#
# Project created by QtCreator 2016-05-02T12:44:17
#
#-------------------------------------------------

QT       += core gui\
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tutorial1
TEMPLATE = app


SOURCES += main.cpp \
    drum.cpp \
    bits.cpp \
    bits2.cpp \
    setgame.cpp \
    score.cpp \
    counter.cpp

HEADERS  += \
    drum.h \
    bits.h \
    bits2.h \
    setgame.h \
    score.h \
    counter.h

FORMS    +=

RESOURCES += \
    res.qrc
