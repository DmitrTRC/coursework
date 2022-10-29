//
// Created by Dmitry Morozov on 29/10/22.
//

#include "Play_Again.hpp"

#include <string>


PlayAgain::PlayAgain(WINDOW *parentWindow) : _parentWindow(parentWindow) {

    getmaxyx(_parentWindow, yMax, xMax);
}

bool PlayAgain::runGetChoice() {

    int choice = 0;
    int highlight = 0;

    keypad(_parentWindow, true);

    std::string choices[2] = {"     YES     ", "     NO     "};


    mvwprintw(_parentWindow, yMax / 2 - 2, xMax / 2 - 10, "Do you want to play again?");

    while (true) {
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                wattron(_parentWindow, A_REVERSE);
            }
            mvwprintw(_parentWindow, yMax / 2 + i, xMax / 2 - 2, choices[i].c_str());
            wattroff(_parentWindow, A_REVERSE);
        }
        choice = wgetch(_parentWindow);
        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 2) {
                    highlight = 1;
                }
                break;
            default:
                break;
        }
        if (choice == 10) {
            break;
        }
    }

    keypad(_parentWindow, false);

    return highlight == 0;
}


