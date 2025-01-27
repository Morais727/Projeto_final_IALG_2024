#include <iostream>
#include "utils.h"
#include <ncurses.h> // Visualizações sofisticadas

using namespace std;

// Menu 1
int printMenu1() 
{
  curs_set(0); // Esconde o cursor
    const string header = R"(
  ***************************************
  *       __  __                        *
  *      |  \/  | ___ _ __  _   _       *
  *      | |\/| |/ _ \ '_ \| | | |      *
  *      | |  | |  __/ | | | |_| |      * 
  *      |_|  |_|\___|_| |_|\__,_|      *
  *                                     *
  ***************************************
)";
    const int optionCount = 5;
    const string options[optionCount] = {
        " ==> Buscar Registros",
        " ==> Alterar Registros",
        " ==> Excluir Registros",
        " ==> Cadastrar Novos Registros",
        " ==> Sair"
    };

    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 4)
    return choice + 1;
}