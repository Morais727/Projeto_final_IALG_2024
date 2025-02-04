/**
 * @file mostrarDetalhesAcomodacao.cpp
 * @brief Implementação de uma função para exibir detalhes de uma acomodação específica.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include "utils.h"
#include <ncurses.h>  // Para as funções ncurses (clear, mvprintw, getch)
#include <iostream>    // Para entrada e saída padrão, como "cout" e "cin"
#include <string>      // Para o tipo string (se necessário para manipulação de strings)

using namespace std;

/**
 * @brief Exibe os detalhes de uma acomodação com base no ID selecionado.
 * @param registros Um array de estruturas `acomodacoes` contendo os dados das acomodações.
 * @param tamanhoAtual O tamanho atual do array de registros.
 * @param idSelecionado O ID da acomodação que se deseja exibir.
 * @param tamanhoInicial O índice inicial para a busca no array.
 * @param tamanhoFinal O índice final para a busca no array.
 */
void mostrarDetalhesAcomodacao(acomodacoes* registros, int tamanhoAtual, int idSelecionado, int& tamanhoInicial, int& tamanhoFinal) 
{
    bool encontrado = false;

    // Verifica se o idSelecionado é válido
    if (idSelecionado <= 0) 
    {
        clear();
        mvprintw(0, 0, "ID inválido.");
        mvprintw(1, 0, "Pressione qualquer tecla para voltar.");
        refresh();
        curs_set(0); // Esconde o cursor
        getch();
        return;
    }

    // Buscar a acomodação pelo id
    for (int i = tamanhoInicial; i < tamanhoAtual; i++) 
    {
        if (registros[i].id == idSelecionado) 
        {
            clear(); // Limpa a tela

            // Exibe os detalhes da acomodação à esquerda
            mvprintw(2, 0, "Detalhes da Acomodacao:");
            mvprintw(3, 0, "ID: %lld", registros[i].id);
            mvprintw(4, 0, "Nome: %s", registros[i].name);
            mvprintw(5, 0, "Host Name: %s", registros[i].host_name);
            mvprintw(6, 0, "Tipo de Acomodação: %s", registros[i].property_type);
            mvprintw(7, 0, "Preço: %.2f", registros[i].price);
            mvprintw(8, 0, "Número de Quartos: %d", registros[i].bedrooms);
            mvprintw(9, 0, "Número de Banheiros: %d", registros[i].bathrooms);
            mvprintw(10, 0, "Avaliação: %.2f", registros[i].review_scores_rating);
            mvprintw(11, 0, "Latitude: %.2f", registros[i].latitude);
            mvprintw(12, 0, "Longitude: %.2f", registros[i].longitude);

            // Mostrar a opção para voltar
            mvprintw(14, 0, "Pressione qualquer tecla para voltar ao menu.");
            refresh();

            getch();  // Espera por qualquer tecla para voltar
            encontrado = true;
            break;
        }
    }

    if (!encontrado) 
    {
        clear();  // Limpa a tela
        mvprintw(0, 0, "Acomodação não encontrada.");
        mvprintw(1, 0, "Pressione qualquer tecla para voltar.");
        refresh();
        getch();  // Espera por qualquer tecla para voltar
    }
}