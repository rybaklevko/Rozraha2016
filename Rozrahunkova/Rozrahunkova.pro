TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    train.cpp \
    schedule.cpp \
    times.cpp

HEADERS += \
    train.h \
    schedule.h \
    times.h
