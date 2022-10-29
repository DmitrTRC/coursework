//
// Created by Dmitry Morozov on 29/10/22.
//

#ifndef COURSEWORK_DEV_PLAY_AGAIN_HPP
#define COURSEWORK_DEV_PLAY_AGAIN_HPP

#include "curses.h"

class PlayAgain {
public:
    explicit PlayAgain(WINDOW *);

    bool runGetChoice();

private:
    int yMax, xMax;
    WINDOW *_parentWindow;

};


#endif //COURSEWORK_DEV_PLAY_AGAIN_HPP
