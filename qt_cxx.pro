QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += \
    code \
    code/include \
    code/notification

SOURCES += \
    code/main.cpp \
    code/notification/meta_notification_center.cpp \
    code/widgets/mainwindow.cpp \
    code/producer.cpp \
    code/consumer.cpp

HEADERS += \
    code/notification/meta_notification_center.h \
    code/widgets/mainwindow.h \
    code/consumer.h \
    code/producer.h

FORMS += \
    code/widgets/mainwindow.ui

UI_DIR = $$PWD/code/include/uic

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
