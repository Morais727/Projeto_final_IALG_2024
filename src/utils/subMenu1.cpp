/**
 * @file subMenu1.cpp
 * @brief Implementação de um submenu interativo para importação e adição de dados.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include "utils.h"
#include <ncurses.h> // Visualizações sofisticadas

using namespace std;

/**
 * @brief Exibe o Submenu 1 e permite ao usuário interagir com as opções.
 * @return O número da opção selecionada pelo usuário (1 a 3).
 */
int printSubMenu1() 
{
    curs_set(0); // Esconde o cursor

    // Cabeçalho do submenu
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

    // Opções do submenu
    const int optionCount = 3;
    const string options[optionCount] = {
        "  Importar CSV                                                 ",
        "  Adicionar Manualmente                                        ",       
        "  Voltar                                                       ",
    };

    // Exibe o menu interativo e obtém a escolha do usuário
    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 3)
    return choice + 1;
}