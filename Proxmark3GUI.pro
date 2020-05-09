QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    common/pm3process.cpp \
    common/util.cpp \
    module/mifare.cpp \
    ui/mf_sim_simdialog.cpp \
    ui/mf_uid_parameterdialog.cpp \
    ui/mainwindow.cpp \
    ui/mf_attack_hardnesteddialog.cpp \

HEADERS += \
    common/pm3process.h \
    common/util.h \
    module/mifare.h \
    ui/mf_sim_simdialog.h \
    ui/mf_uid_parameterdialog.h \
    ui/mainwindow.h \
    ui/mf_attack_hardnesteddialog.h \

FORMS += \
    ui/mf_sim_simdialog.ui \
    ui/mf_uid_parameterdialog.ui \
    ui/mainwindow.ui \
    ui/mf_attack_hardnesteddialog.ui

TRANSLATIONS += \
    lang/zh_CN.ts \
    lang/en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

VERSION = 0.1.1
QMAKE_TARGET_PRODUCT = "Proxmark3GUI"
QMAKE_TARGET_DESCRIPTION = "Proxmark3GUI"
QMAKE_TARGET_COMPANY = "wh201906"
