/**
 * @file imprimeMenu.cpp
 * @brief Implementação do menu de listagem e filtragem de acomodações.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
#include <ncurses.h>
#include "utils.h"

using namespace std;

/**
 * @brief Exibe o menu de listagem de acomodações com opções de filtros e ordenação.
 * 
 * Esta função permite ao usuário visualizar as acomodações disponíveis, aplicar filtros (como faixa de preço),
 * ordenar os registros (por preço crescente, decrescente ou número de reviews) e acessar detalhes de um registro específico.
 * O menu é interativo e suporta navegação entre páginas de resultados.
 * 
 * @param registros Ponteiro para o array de registros originais de acomodações.
 * @param tamanhoAtual Número total de registros armazenados no array.
 * 
 * @details
 * - Cria uma cópia do array de registros para aplicar filtros sem modificar os dados originais.
 * - Utiliza a função `imprimeValores` para exibir os registros paginados.
 * - Oferece opções para ordenar os registros por preço ou número de reviews.
 * - Permite filtrar os registros por faixa de preço.
 * - Permite ao usuário visualizar detalhes de uma acomodação específica.
 * - Reinicia os filtros aplicados quando necessário.
 * 
 * @note
 * - A função utiliza alocação dinâmica de memória para criar cópias dos registros filtrados.
 * - A memória alocada é liberada ao final da execução da função.
 * - O cursor é ocultado durante a interação com o menu.
 */
void menuImprime(acomodacoes* registros, int tamanhoAtual) 
{
    int tamanhoInicial = 0, tamanhoFinal = 35; // Intervalo de exibição dos registros
    
    // Criar uma cópia inicial do array de registros
    acomodacoes* registrosFiltrados = new acomodacoes[tamanhoAtual];
    for (int i = 0; i < tamanhoAtual; ++i) 
    {
        registrosFiltrados[i] = registros[i];
    }
    int tamanhoFiltrado = tamanhoAtual; // Tamanho atual do array filtrado
    bool running = true; // Controla o loop do menu

    while (running) 
    {
        // Exibe os registros paginados e obtém a seleção do usuário
        int selecionado = imprimeValores(registrosFiltrados, tamanhoFiltrado, tamanhoInicial, tamanhoFinal);

        if (selecionado == -20) 
        {
            clearConsole(); // Limpa a tela
            curs_set(0); // Oculta o cursor

            // Exibe o menu de filtros e ordenação
            int seleciona = printSubMenu1();

            if (seleciona == 1) 
            {
                // Ordena os registros por preço crescente
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceCrescente);
            } 
            else if (seleciona == 2) 
            {
                // Ordena os registros por preço decrescente
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceDecrescente);
            } 
            else if (seleciona == 3) 
            {
                // Ordena os registros por número de reviews
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorReviews);
            } 
            else if (seleciona == 4) 
            {
                // Filtra os registros por faixa de preço
                float precoMin, precoMax;
                cout << "Digite o preço mínimo: ";
                cin >> precoMin;
                cout << "Digite o preço máximo: ";
                cin >> precoMax;

                clearConsole(); // Limpa a tela

                // Valida a faixa de preço
                if (precoMin >= 0 && precoMax > 0 && precoMin < precoMax) 
                {
                    // Criar um array temporário do mesmo tamanho de registrosFiltrados
                    acomodacoes* filtrados = new acomodacoes[tamanhoFiltrado];
                    int tamanhoFiltradoAtual = 0;

                    // Aplica o filtro de preço
                    for (int i = 0; i < tamanhoFiltrado; i++) 
                    {
                        if (registrosFiltrados[i].price >= precoMin && registrosFiltrados[i].price <= precoMax) 
                        {
                            filtrados[tamanhoFiltradoAtual++] = registrosFiltrados[i];
                        }
                    }

                    if (tamanhoFiltradoAtual > 0) 
                    {
                        // Criar um novo array com o tamanho exato
                        acomodacoes* novoArray = new acomodacoes[tamanhoFiltradoAtual];
                        for (int i = 0; i < tamanhoFiltradoAtual; i++) 
                        {
                            novoArray[i] = filtrados[i];
                        }

                        // Libera o array antigo antes de atribuir o novo
                        delete[] registrosFiltrados;
                        registrosFiltrados = novoArray;

                        tamanhoFiltrado = tamanhoFiltradoAtual;
                        tamanhoInicial = 0;
                        tamanhoFinal = 35;

                        // Ordena os registros filtrados por preço crescente
                        quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceCrescente);
                    } 
                    else 
                    {
                        // Nenhum registro encontrado no filtro
                        cout << "Nenhuma acomodação encontrada nessa faixa de preço." << endl;
                        sleep(2);
                        clearConsole(); // Limpa a tela
                    }

                    // Libera o array temporário usado para filtrar
                    delete[] filtrados;
                } 
                else 
                {
                    // Faixa de preço inválida
                    cout << "Faixa de preço inválida. O preço mínimo deve ser >= 0 e menor que o preço máximo." << endl;
                    sleep(2);
                    clearConsole(); // Limpa a tela
                }
            }
            else if (seleciona == 5) 
            {
                
                string campo, valor;
                campo = printSubMenu4();
                cout << "Digite o valor a ser buscado" << endl;
                cin >> valor;

                clearConsole(); // Limpa a tela

                listarPorCampo(registrosFiltrados,tamanhoAtual,campo,valor);
            } 
            else if (seleciona == 6) 
            {
                // Reinicia os filtros aplicados
                delete[] registrosFiltrados;
                registrosFiltrados = new acomodacoes[tamanhoAtual];
                for (int i = 0; i < tamanhoAtual; ++i) 
                {
                    registrosFiltrados[i] = registros[i];
                }
                tamanhoFiltrado = tamanhoAtual;
                tamanhoInicial = 0;
                tamanhoFinal = 35;
            } 
            else 
            {
                // Seleção inválida
                cout << "Seleção inválida." << endl;
                sleep(2);
            }
        } 
        else if (selecionado == -10) 
        { 
            // Sai do loop e encerra o menu
            running = false;
        } 
        else if (selecionado >= 0) 
        {
            // Exibe os detalhes da acomodação selecionada
            curs_set(0);
            mostrarDetalhesAcomodacao(registrosFiltrados, tamanhoFiltrado, selecionado, tamanhoInicial, tamanhoFinal);
        }
    }

    // Libera a memória alocada para os registros filtrados
    delete[] registrosFiltrados;
}