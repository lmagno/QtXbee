QT       += core
greaterThan(QT_MAJOR_VERSION, 4): QT += serialport
QT       -= gui

CONFIG += c++11

TARGET = ../QtXBeeSample
OBJECTS_DIR = ../build
MOC_DIR = ../build

CONFIG += console
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): CONFIG += serialport

TEMPLATE = app

INCLUDEPATH += $$PWD/../src
INCLUDEPATH += $$PWD/../src/QXBeePacket
DEPENDPATH += $$PWD/../src

SOURCES += main.cpp

greaterThan(QT_MAJOR_VERSION, 4) {
LIBS            += \
				-L/usr/lib \
				-L/usr/local/lib \

} else {

LIBS            += \
				-L/usr/lib \
				-lQtSerialPort \
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lQXBee
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lQXBee
else:unix: LIBS += -L$$OUT_PWD/../src/ -lQXBee
win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/libQXBee.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/libQXBee.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/release/QXBee.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../src/debug/QXBee.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../src/libQXBee.a
