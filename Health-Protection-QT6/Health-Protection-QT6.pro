QT       += core gui
QT += network
QT += multimedia
QT += multimedia network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog1.cpp \
    dialog1x.cpp \
    dialog2.cpp \
    dialog3.cpp \
    dialog4.cpp \
    dialog5.cpp \
    dialog6.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialog1.h \
    dialog1x.h \
    dialog2.h \
    dialog3.h \
    dialog4.h \
    dialog5.h \
    dialog6.h \
    mainwindow.h

FORMS += \
    dialog1.ui \
    dialog1x.ui \
    dialog2.ui \
    dialog3.ui \
    dialog4.ui \
    dialog5.ui \
    dialog6.ui \
    mainwindow.ui

TRANSLATIONS += \
    Health-Protection-QT6_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../../Desktop/39414350.jpg

RESOURCES +=
