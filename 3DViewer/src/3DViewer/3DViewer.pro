QT += core gui
QT += opengl
QT += gui widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

win32: {
LIBS += -lopengl32 -lglu32
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    ./backend/model.c \
    ./backend/parcer.c \
    ./backend/transformations.c

HEADERS += \
    glwidget.h \
    mainwindow.h \
    ./backend/model.h \
    ./backend/parcer.h \
    ./backend/transformations.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(../QtGifImage/src/gifimage/qtgifimage.pri)
