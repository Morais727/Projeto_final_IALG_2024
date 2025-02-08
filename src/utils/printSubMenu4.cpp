/**
 * @file menu2.cpp
 * @brief Implementação de um menu interativo para ordenação e filtragem de dados.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include "utils.h"
#include <ncurses.h>  // Para as funções ncurses (clear, mvprintw, getch)

using namespace std;

/**
 * @brief Exibe o Menu 2 e permite ao usuário interagir com as opções de ordenação e filtragem.
 * @return O número da opção selecionada pelo usuário (1 a 5).
 */
int printSubMenu4()
{
    curs_set(0); // Esconde o cursor

    // Cabeçalho do menu
    const string header = R"(
  **********************************************************************
  *  _____ _ _ _                                                       *
  *  |  ___(_) | |_ _ __ __ _ _ __    ___ __ _ _ __ ___  _ __   ___    *
  *  | |_  | | | __| '__/ _` | '__|  / __/ _` | '_ ` _ \| '_ \ / _ \   *
  *  |  _| | | | |_| | | (_| | |    | (_| (_| | | | | | | |_) | (_) |  * 
  *  |_|   |_|_|\__|_|  \__,_|_|     \___\__,_|_| |_| |_| .__/ \___/   * 
  *                                                     |_|            *
  **********************************************************************
  )";

    // Opções do menu
    const int optionCount = 4;
    const string options[optionCount] = {
        "  Nome da acomodação                                           ",
        "  Nome do anfitrião                                            ",
        "  Número de quartos                                            ",
        "  Número de banheiros                                          ",
    };

    // Exibe o menu interativo e obtém a escolha do usuário
    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 5)
    return choice;
}