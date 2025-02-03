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

void menuImprime(acomodacoes* registros, int tamanhoAtual) {
    int tamanhoInicial = 0, tamanhoFinal = 35;
    
    // Criar uma cópia inicial do array de registros
    acomodacoes* registrosFiltrados = new acomodacoes[tamanhoAtual];
    for (int i = 0; i < tamanhoAtual; ++i) {
        registrosFiltrados[i] = registros[i]; // Copiar os dados originais
    }
    // cout << "AQUI." << endl;
    // sleep(2);
    int tamanhoFiltrado = tamanhoAtual;
    bool running = true;

    while (running) {
        int selecionado = imprimeValores(registrosFiltrados, tamanhoFiltrado, tamanhoInicial, tamanhoFinal);

        if (selecionado == -20) {
            clearConsole();
            curs_set(0);

            int seleciona = printMenu2(); // Exibe o menu de filtros;

            if (seleciona == 1) {
                // Ordenação por preço
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceCrescente);
            } else if (seleciona == 2) {
                // Ordenação por avaliações
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceDecrescente);
            } else if (seleciona == 3) {
                // Ordenação por avaliações
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorReviews);
            } else if (seleciona == 4) {
                // Filtragem por faixa de preço
                float precoMin, precoMax;
                cout << "Digite o preço mínimo: ";
                cin >> precoMin;
                cout << "Digite o preço máximo: ";
                cin >> precoMax;

                acomodacoes* filtrados = new acomodacoes[tamanhoFiltrado];
                int tamanhoFiltradoAtual = 0;

                for (int i = 0; i < tamanhoFiltrado; i++) {
                    if (registrosFiltrados[i].price >= precoMin && registrosFiltrados[i].price <= precoMax) {
                        filtrados[tamanhoFiltradoAtual++] = registrosFiltrados[i];
                    }
                }

                if (tamanhoFiltradoAtual > 0) {
                    // Atualizar os registros filtrados
                    delete[] registrosFiltrados; // Liberar a memória antiga
                    registrosFiltrados = filtrados;
                    tamanhoFiltrado = tamanhoFiltradoAtual;
                    tamanhoInicial = 0;
                    tamanhoFinal = 35;
                } else {
                    delete[] filtrados; // Liberar memória se não houver registros filtrados
                    cout << "Nenhuma acomodação encontrada nessa faixa de preço." << endl;
                    sleep(2);
                }
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceCrescente);
            } else if (seleciona == 5) {
                // Restaurar a cópia original dos registros
                delete[] registrosFiltrados; // Liberar a memória dos dados filtrados
                registrosFiltrados = new acomodacoes[tamanhoAtual];
                for (int i = 0; i < tamanhoAtual; ++i) {
                    registrosFiltrados[i] = registros[i]; // Recriar a cópia dos dados originais
                }
                tamanhoFiltrado = tamanhoAtual;
                tamanhoInicial = 0;
                tamanhoFinal = 35;
            } else {
                cout << "Seleção inválida." << endl;
                sleep(2);
            }
        } else if (selecionado == -10) { // Voltar ao menu principal
            running = false;
        } else if (selecionado >= 0) {
            curs_set(0);
            mostrarDetalhesAcomodacao(registrosFiltrados, tamanhoFiltrado, selecionado, tamanhoInicial, tamanhoFinal);
        }
    }

    // Liberar a memória dos registros filtrados antes de sair
    delete[] registrosFiltrados;
}
