/**
 * @file barraCarregamento.cpp
 * @author Marcos Morais
 * @date 03/02/2025
 * @brief Exibe uma barra de carregamento animada na interface `ncurses`.
 * 
 * Esta função calcula dinamicamente a largura da barra de progresso com base no tamanho da tela
 * e no progresso atual. A barra é centralizada e exibida no meio da tela.
 */

#include <iostream>
#include <fstream>
#include "utils.h"
#include <ncurses.h>
#include <unistd.h>  // Para a função usleep()

using namespace std;

/**
 * @brief Exibe uma barra de carregamento animada na interface `ncurses`.
 * 
 * @param progresso Valor atual do progresso (quantidade concluída).
 * @param total Valor total representando 100% do progresso.
 */
void exibirBarraCarregamento(int progresso, int total) 
{
    int linhas, colunas;
    getmaxyx(stdscr, linhas, colunas);

    int larguraBarra = colunas - 30;
    float percentual = (float)progresso / total;
    int posicaoPreenchida = percentual * larguraBarra;

    string barraPreenchida(posicaoPreenchida, '=');
    string barraVazia(larguraBarra - posicaoPreenchida, ' ');

    int espacoEsquerda = (colunas - larguraBarra) / 2;

    // Limpa a tela e exibe a barra de progresso
    clear();
    mvprintw(linhas / 2, espacoEsquerda, "[%s%s] %d%%", barraPreenchida.c_str(), barraVazia.c_str(), (int)(percentual * 100));
    
    // Atualiza a interface `ncurses` e força a exibição imediata
    refresh();
    usleep(5);  // Pequeno atraso para visualização da animação 
}

