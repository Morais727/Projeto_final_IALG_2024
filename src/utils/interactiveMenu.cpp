/**
 * @file interactiveMenu.cpp
 * @brief Implementação de um menu interativo usando a biblioteca ncurses.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <string>
#include <ncurses.h>

/**
 * @brief Exibe um menu interativo e permite ao usuário navegar e selecionar uma opção.
 * @param options Um array de strings contendo as opções do menu.
 * @param optionCount O número de opções no array.
 * @param header O cabeçalho do menu, exibido na parte superior.
 * @return O índice da opção selecionada pelo usuário.
 */
int interactiveMenu(const std::string options[], int optionCount, const std::string& header) 
{
    initscr(); // Inicializa o ncurses
    cbreak();  // Desabilita o buffer de linha, permitindo leitura imediata de caracteres
    noecho();  // Não exibe a entrada do usuário
    keypad(stdscr, TRUE); // Habilita a leitura de teclas especiais (como setas)

    int highlight = 0; // Índice da opção atualmente destacada
    int choice = -1;   // Índice da opção selecionada pelo usuário
    int input;         // Entrada do usuário

    while (choice == -1) 
    {
        clear(); // Limpa a tela
        printw("%s\n", header.c_str()); // Exibe o cabeçalho

        // Exibe as opções do menu
        for (int i = 0; i < optionCount; ++i) 
        {
            if (i == highlight) {
                attron(A_REVERSE); // Destaca a opção atual
                printw("%s\n", options[i].c_str());
                attroff(A_REVERSE);
            } else {
                printw("%s\n", options[i].c_str());
            }
        }

        input = getch(); // Captura a entrada do usuário
        switch (input) 
        {
            case KEY_UP: // Navega para a opção acima
                highlight = (highlight == 0) ? optionCount - 1 : highlight - 1;
                break;
            case KEY_DOWN: // Navega para a opção abaixo
                highlight = (highlight == optionCount - 1) ? 0 : highlight + 1;
                break;
            case '\n': // Seleciona a opção atual
                choice = highlight;
                break;
            default:
                break;
        }
    }

    endwin(); // Finaliza o ncurses
    return choice; // Retorna o índice da opção selecionada
}