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
int printSubMenu1()
{
    curs_set(0); // Esconde o cursor

    // Cabeçalho do menu
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

    // Opções do menu
    const int optionCount = 6;
    const string options[optionCount] = {
        "  Ordenar por preço crescente                                  ",
        "  Ordenar por preço decrescente                                ",
        "  Ordenar por número de avaliações (melhor primeiro)           ",
        "  Filtrar por faixa de preço                                   ",
        "  Filtrar por campos específicos                               ", 
        "  Remover filtros                                              ",
    };

    // Exibe o menu interativo e obtém a escolha do usuário
    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 5)
    return choice + 1;
}