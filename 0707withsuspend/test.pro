QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game_over.cpp \
    game_success.cpp \
    main.cpp \
    settingbeginning.cpp \
    suspend.cpp \
    widget.cpp

HEADERS += \
    game_over.h \
    game_success.h \
    settingbeginning.h \
    suspend.h \
    widget.h

FORMS += \
    game_over.ui \
    game_success.ui \
    settingbeginning.ui \
    suspend.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture_for_game.qrc
