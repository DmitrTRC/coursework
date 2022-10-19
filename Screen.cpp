#include "Screen.h"
#include "palette.h"

#include <curses.h>

void screen() // Rename to something like "InitScreen
{

    initscr();                         //включение графической библиотеки
    keypad(stdscr, TRUE);              //обработка командных клавиш (стрелки)
    curs_set(0);                       //убирает мигающий курсор в консоли
    InitPalette();
    noecho();

//FIXME: Wrong logic. You've  already  used mvprintw!
    //заполнение поля?
    attron(COLOR_PAIR(Screen_palett)); //TODO: Separate all colors to the separate file
    chtype ch = ' ' | COLOR_PAIR(Screen_palett);        //функционал из библиотеки
    addch(ch);                                          //заполнение поля (функционал из библиотеки)
    mvprintw(7, 2,
             "     ..-:***************.    ...:****************:     ..:****************..       ..:*:--:*-.             ");
    mvprintw(8, 2,
             "   ..*-...              --  ..*... .             .:  ..*...               :.       .*.........:-.          ");
    mvprintw(9, 2,
             " .*....-**::::::::::::::.  :.  .:*:::::::::::::::- .*.  .:*:::::::::::::::..     .*...*.:-:-. --.          ");
    mvprintw(10, 2,
             " .*. .:--*-.............:-.:-..:--:-..............: :. .:-::-.............*.     .:. .:.*.-::. .:.         ");
    mvprintw(11, 2,
             " :. .:.*. ..............--.*. .:--   .............: *. .::.   ............:.    .-: .--:.  :.*. .*.        ");
    mvprintw(12, 2,
             " *. .*-- .:................*. .:--  :-............. *  .::. .*...............   .*. .*--.  .*-: .--        ");
    mvprintw(13, 2,
             " :. .:.*..       ..::..   .*. .:--            .:    *  .::. .*.:          :.   .:. .*.*     -::...:..      ");
    mvprintw(14, 2,
             " .*. .::-*::-----.....*.  .*. .:-:::::::::::::::    *  .::. .*.*:::::::.  :.  .--..--*.     .:.*...*.      ");
    mvprintw(15, 2,
             "  .*-.  .:******:.-:...:-..*. .:-**************-.   *  .::. .*.******:--  :. ..*...:--  .*-  .*.:. -:.     ");
    mvprintw(16, 2,
             "    .::...      ..:.*...*..*. .:--   .        .:    *  .::. .*.:    .*--  :. .:. .*.*. .:.:....::. .:.     ");
    mvprintw(17, 2,
             "        .-:::::*. .*.:. --.*. .:--  :::::::::::-    *  .::. .*.::*. .*--  :..-- .--*.  -:..*.  :.*. .*.    ");
    mvprintw(18, 2,
             " *.............. ..*--. :..*. .:--. .............-: *  .::.  ...... .*--  :..*. .:-- ..*:....  .*.: .-:    ");
    mvprintw(19, 2,
             " *...............::-:...*..:...:.*-...............: :.  *.*..........*--  :.*...*.:  .:-:........::-..:.   ");
    mvprintw(20, 2,
             " ...............-*:.  .*....*...-*-................ .*. .-*-..........--  ::-. :-*. .--............*...*.  ");
    mvprintw(21, 2,
             " *.                ..*.     .::..                .:  .::..               .-:...:--  .*..:.             -:. ");
    mvprintw(22, 2,
             " *--------------:**-..       ...:*::-------------::    ..:*::-----------------*.*---*. .*---------------*. ");


    attron(COLOR_PAIR(TEXT));
    mvprintw(28, 92, "press any key");

    getch();

}

