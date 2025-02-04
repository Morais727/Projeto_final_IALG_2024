/**
 * @file menu1.cpp
 * @brief Implementação de um menu interativo para manipulação de dados.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include "utils.h"
#include <ncurses.h> // Visualizações sofisticadas

using namespace std;

/**
 * @brief Exibe o Menu 1 e permite ao usuário interagir com as opções.
 * @return O número da opção selecionada pelo usuário (1 a 6).
 */
int printMenu1() 
{
    curs_set(0); // Esconde o cursor

    // Cabeçalho do menu
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

    // Opções do menu
    const int optionCount = 6;
    const string options[optionCount] = {
        "  Mostrar Dados                                                ",
        "  Alterar Dados                                                ",
        "  Excluir Dados                                                ",
        "  Adicionar Dados                                              ",                         
        "  Exportar dados                                               ",
        "  Sair                                                         "
    };

    // Exibe o menu interativo e obtém a escolha do usuário
    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 6)
    return choice + 1;
}