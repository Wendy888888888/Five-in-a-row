
QT       += core gui
QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Five
TEMPLATE = app


SOURCES += Main.cpp\
        five-ai.cpp \
        five-event.cpp \
        five-game.cpp \
        five-menu.cpp \
        five-ui.cpp

HEADERS  += Five.h

FORMS    +=
