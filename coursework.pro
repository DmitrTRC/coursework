TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Board.cpp \
        Game.cpp \
        Menu.cpp \
        Palette.cpp \
        level.cpp \
        main.cpp

LIBS += -L$$PWD/../PDCurses/wincon/ -lpdcurses


INCLUDEPATH += $$PWD/../PDCurses
DEPENDPATH += $$PWD/../PDCurses

HEADERS += \
    Board.h \
    Game.h \
    GameState.h \
    Menu.h \
    palette.h

