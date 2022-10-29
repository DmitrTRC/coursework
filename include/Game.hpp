#ifndef GAME_H
#define GAME_H

#include "Bonus.hpp"
#include "Board.hpp"
#include "Menu.hpp"
#include "T_Rex.hpp"
#include "T_Rex_Step.hpp"

constexpr int BOARD_WIDTH = 110;

constexpr int BOARD_HEIGHT = 30;

class Game {

public:
    Game(int, int);

    Game();

    ~Game();


    void processInput();

    void updateState();

    void redraw();

    void run();

    void ProcessMenu();

    [[nodiscard]] bool isRunning() const;

private:
    GameBoard *_board;
    Menu *_menu;
    Bonus *_bonus{};
    T_rex *_t_rex_move1;
    T_Rex_step *_t_rex_move2;
    DrawableRect *_cur_t_rex;


    bool _is_step = false; // true - step, false - run

    bool _isRunning;

};


#endif // GAME_H
