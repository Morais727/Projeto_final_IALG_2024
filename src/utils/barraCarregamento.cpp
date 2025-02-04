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
    
    // Obtém as dimensões da janela (número de linhas e colunas)
    getmaxyx(stdscr, linhas, colunas);

    // Define a largura da barra de carregamento com base na largura da tela
    int larguraBarra = colunas - 30;  // Deixa um pequeno espaço nas laterais

    // Calcula o percentual de progresso
    float percentual = (float)progresso / total;
    int posicaoPreenchida = percentual * larguraBarra;

    // Constrói a barra de progresso com '=' para a parte preenchida e ' ' para a parte vazia
    string barraPreenchida(posicaoPreenchida, '=');
    string barraVazia(larguraBarra - posicaoPreenchida, ' ');

    // Centraliza a barra horizontalmente
    int espacoEsquerda = (colunas - larguraBarra) / 2;

    // Limpa a tela antes de atualizar a barra
    clear();
    
    // Exibe a barra de carregamento centralizada na tela
    mvprintw(linhas / 2, espacoEsquerda, "[%s%s] %d%%", barraPreenchida.c_str(), barraVazia.c_str(), (int)(percentual * 100));
    
    // Pequeno atraso para visualização da animação
    usleep(5);  

    // Atualiza a interface `ncurses`
    refresh();
}
