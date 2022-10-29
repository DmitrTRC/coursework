#include "Bonus.hpp"
#include "Cactus_1.hpp"
#include "Game.hpp"
#include "Drawable.hpp"
#include "palette.hpp"
#include "T_Rex.hpp"
#include "T_Rex_Step.hpp"
#include <vector>

#include <curses.h>


Game::Game(int y, int x) {

    noecho();
    curs_set(0);
    cbreak();

    _board = new GameBoard(y, x);
    _board->initBoard();
    _menu = new Menu(_board->getBoard());
    _isRunning = true;
    _t_rex_move1 = new T_rex(_board->getGroundY() - 6, 10); // Plus height of T-rex. Refactor it to constant
    _t_rex_move2 = new T_Rex_step(_board->getGroundY() - 6, 10);
    _cur_t_rex = nullptr;

}


bool Game::isRunning() const {

    return _isRunning;
}

Game::~Game() {

    attrset(A_NORMAL);
    delete _bonus;
    delete _t_rex_move1;
    delete _t_rex_move2;
    delete _board;

    endwin();

}

void Game::processInput() {

    chtype userInput = _board->getInput();
    switch (userInput) {
        case 'q':
            _isRunning = false;
            break;
        case ' ':
            if (!_cur_t_rex->isJump()) {
                beep();
                _board->ClearObject(_cur_t_rex);
                _board->setTimeOut(50);
                _cur_t_rex->jump();
            }

            break;
        case 'm':
            _board->setTimeOut(-1);
            ProcessMenu();
            redraw();
            _board->setTimeOut(200);
            break;

        case 'p':
            _board->setTimeOut(-1);
            while (_board->getInput() != 'p');
            _board->setTimeOut(200);
            break;

        default:
            break;
    }

}

Game::Game() : Game(BOARD_HEIGHT, BOARD_WIDTH) {

}

void Game::redraw() {

    _board->refreshBoard();


}

void Game::updateState() {

//    if (_bonus == nullptr) {
//        _bonus = new Bonus(10, 50);
//        _board->add(_bonus);
//
//    }
    _updateCacti();

    if (_is_step) {
        _cur_t_rex = _t_rex_move1;
    } else {
        _cur_t_rex = _t_rex_move2;
    }


    if (_cur_t_rex->isJump()) {

        _board->ClearObject(_cur_t_rex);
        _cur_t_rex->move();
        _board->add(_cur_t_rex);
        if (!_cur_t_rex->isJump()) {
            _board->setTimeOut(300);
        }

    } else {
        _board->ClearObject(_cur_t_rex);
        _board->add(_cur_t_rex);
        _is_step = !_is_step;
    }
}


void Game::run() { // Main LOOP

    while (isRunning()) {

        processInput();

        updateState();

        redraw();

    }

}

void Game::ProcessMenu() {

    auto result = _menu->runGetChoice();
    if (result.empty()) {
        return;
    }
    beep();


}

void Game::_updateCacti() {

    if (cacti.empty()) {
        cacti.push_back(new Cactus1(_board->getGroundY() - 8, _board->getWidth() - 20));
        _board->add(cacti.back());
    }

    for (auto cactus: cacti) {
        _board->ClearObject(cactus);
        cactus->move();
        _board->add(cactus);
        if (cactus->getX() < 0) {
            _board->ClearObject(cactus);
            cacti.erase(cacti.begin());
            delete cactus;
        }
    }


}



