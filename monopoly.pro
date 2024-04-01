QT += core gui

QT += widgets

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    Game_Board.cpp \
    action.cpp \
    bank.cpp \
    boardgame.cpp \
    bottomBar.cpp \
    card.cpp \
    card_money.cpp \
    card_move.cpp \
    centralwidget.cpp \
    dice.cpp \
    goToAction.cpp \
    guiplayers.cpp \
    mainwindow.cpp \
    money_action.cpp \
    move_action.cpp \
    player.cpp \
    space.cpp

HEADERS += \
    Game_Board.h \
    action.h \
    bank.h \
    bottomBar.h \
    card.h \
    card_money.h \
    card_move.h \
    centralwidget.h \
    dice.h \
    goToAction.h \
    guiplayers.h \
    mainwindow.h \
    money_action.h \
    move_action.h \
    player.h \
    space.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
