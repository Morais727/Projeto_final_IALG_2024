#include <iostream>
#include "utils.h"
#include <ncurses.h>  // Para as funções ncurses (clear, mvprintw, getch)

using namespace std;

// Menu 2
int printMenu2()
{
  curs_set(0); // Esconde o cursor
    const string header = R"(
  ****************************************
  *      _____ _ _ _                     *
  *    |  ___(_) | |_ _ __ __ _ _ __     *
  *    | |_  | | | __| '__/ _` | '__|    *
  *    |  _| | | | |_| | | (_| | |       *  
  *    |_|   |_|_|\__|_|  \__,_|_|       *
  *                                      *
  ****************************************
)";
    const int optionCount = 5;
    const string options[optionCount] = {
        " ==> Ordenar por preço crescente",
        " ==> Ordenar por preço decrescente",
        " ==> Ordenar por número de avaliações (melhor primeiro)",
        " ==> Filtrar por faixa de preço",
        " ==> Remover filtros"
    };

    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 4)
    return choice + 1;
}
