#include <iostream>
#include <string>
#include <ncurses.h>

int interactiveMenu(const std::string options[], int optionCount, const std::string& header) {
    initscr(); // Inicializa o ncurses
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int highlight = 0;
    int choice = -1;
    int input;

    while (choice == -1) {
        clear();
        printw("%s\n", header.c_str());
        for (int i = 0; i < optionCount; ++i) {
            if (i == highlight) {
                attron(A_REVERSE);
                printw("%s\n", options[i].c_str());
                attroff(A_REVERSE);
            } else {
                printw("%s\n", options[i].c_str());
            }
        }

        input = getch();
        switch (input) {
            case KEY_UP:
                highlight = (highlight == 0) ? optionCount - 1 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == optionCount - 1) ? 0 : highlight + 1;
                break;
            case '\n':
                choice = highlight;
                break;
            default:
                break;
        }
    }

    endwin(); // Finaliza o ncurses
    return choice;
}
