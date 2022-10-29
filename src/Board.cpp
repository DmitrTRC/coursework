#include "palette.hpp"
#include "Board.hpp"

#include <curses.h>


GameBoard::GameBoard(int height, int width) : _height(height), _width(width) {

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    boardWin = newwin(height, width, yMax / 2 - height / 2, xMax / 2 - width / 2);
    _ground = height - 4;
    setTimeOut(300);
}

void GameBoard::initBoard() {

    clearBoard();
    refreshBoard();

}

void GameBoard::setBorder() {

    box(boardWin, 0, 0);
}

void GameBoard::refreshBoard() {

    wrefresh(boardWin);

}


void GameBoard::clearBoard() {

    wclear(boardWin);
    setBorder();
    drawRoadLine();

}

chtype GameBoard::getInput() const {

    return wgetch(boardWin);

}

void GameBoard::add(Drawable *drawable) {

    drawable->mvAdd(boardWin);
}

void GameBoard::drawRoadLine() {

    mvwhline(boardWin, _ground - 1, 1, ACS_HLINE, _width - 2);
}

void GameBoard::ClearObject(Drawable *drawable) {

    drawable->clear(boardWin);


}

int GameBoard::getGroundY() const {

    return _ground;

}

void GameBoard::setTimeOut(int time_out) {

    wtimeout(boardWin, time_out);

}

WINDOW *GameBoard::getBoard() const {

    return boardWin;

}

int GameBoard::getWidth() const {

    return _width;

}



