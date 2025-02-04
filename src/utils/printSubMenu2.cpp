/**
 * @file printSubMenu2.cpp
 * @brief Exibe o Sub Menu 2 e permite ao usuário interagir com as opções disponíveis.
 * 
 * Esta função exibe um menu interativo com um cabeçalho estilizado e três opções.
 * O cursor é ocultado durante a exibição do menu. O usuário pode navegar pelas opções
 * e selecionar uma delas. A escolha do usuário é retornada como um valor inteiro.
 * 
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include "utils.h"
#include <ncurses.h> 

using namespace std;

/**
 * @brief Exibe o Sub Menu 2 e permite ao usuário interagir com as opções disponíveis.
 * 
 * Esta função exibe um menu interativo com um cabeçalho estilizado e três opções.
 * O cursor é ocultado durante a exibição do menu. O usuário pode navegar pelas opções
 * e selecionar uma delas. A escolha do usuário é retornada como um valor inteiro.
 * 
 * @return int Retorna o número da opção escolhida pelo usuário (1 a 3).
 */
int printSubMenu2() 
{
    curs_set(0); // Esconde o cursor

    // Cabeçalho estilizado do menu
    const string header = R"(
    **************************************************
    *   _____                       _                *
    *  | ____|_  ___ __   ___  _ __| |_ __ _ _ __    *
    *  |  _| \ \/ / '_ \ / _ \| '__| __/ _` | '__|   *
    *  | |___ >  <| |_) | (_) | |  | || (_| | |      *
    *  |_____/_/\_\ .__/ \___/|_|   \__\__,_|_|      *
    *             |_|                                *
    **************************************************
    )";

    // Número de opções disponíveis no menu
    const int optionCount = 3;

    // Opções do menu
    const string options[optionCount] = {
        "  Escolher nome do arquivo a ser exportado                     ",
        "  Nomear como padrão (dados.csv)                               ",
        "  Voltar                                                       ",
    };

    // Exibe o menu interativo e obtém a escolha do usuário
    int choice = interactiveMenu(options, optionCount, header);

    // Incrementa choice para corresponder ao número da opção (1 a 3)
    return choice + 1;
}
