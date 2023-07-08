QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    elem.cpp \
    gameWindow1.cpp \
    game_over.cpp \
    game_success.cpp \
    gamebgm.cpp \
    loseWindow.cpp \
    main.cpp \
    mainbgm.cpp \
    man.cpp \
    mysoundeffect.cpp \
    mytimer.cpp \
    settingbeginning.cpp \
    widget.cpp

HEADERS += \
    barriers.h \
    elem.h \
    gameWindow1.h \
    game_over.h \
    game_success.h \
    gamebgm.h \
    loseWindow.h \
    mainbgm.h \
    man.h \
    mysoundeffect.h \
    mytimer.h \
    settingbeginning.h \
    ui_widget.h \
    widget.h

FORMS += \
    game_over.ui \
    game_success.ui \
    settingbeginning.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    music/music.qrc \
    picture_for_game.qrc

DISTFILES += \
    Timer_Pic/计数器背景板.png \
    Timer_Pic/计数器背景板.png
