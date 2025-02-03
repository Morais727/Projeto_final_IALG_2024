#include <iostream>
#include "utils.h"
#include <ncurses.h> // Visualizações sofisticadas

using namespace std;

// Sub Menu 1
int printSubMenu1() 
{
  curs_set(0); // Esconde o cursor
    const string header = R"(
 ******************************************************
 *       _       _ _      _                           *
 *      / \   __| (_) ___(_) ___  _ __   __ _ _ __    *
 *     / _ \ / _` | |/ __| |/ _ \| '_ \ / _` | '__|   *
 *    / ___ \ (_| | | (__| | (_) | | | | (_| | |      *
 *   /_/   \_\__,_|_|\___|_|\___/|_| |_|\__,_|_|      *
*                                                     *
 ******************************************************
)";
    const int optionCount = 3;
    const string options[optionCount] = {
        " ==> Importa CSV",
        " ==> Adicionar Manualmente",
        " ==> Voltar",
    };

    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 4)
    return choice + 1;
}