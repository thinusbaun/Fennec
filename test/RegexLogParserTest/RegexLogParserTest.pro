#-------------------------------------------------
#
# Project created by QtCreator 2018-01-13T23:06:41
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = RegexLogParserTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        RegexLogParserTest.cpp 

DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../../core
DEPENDPATH += ../../core

LIBS += -L../../core -lcore
PRE_TARGETDEPS += ../../core/libcore.so.1


QMAKE_LFLAGS += -Wl,-rpath,../../core/