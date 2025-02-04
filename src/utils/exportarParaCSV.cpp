/**
 * @file exportarParaCSV.cpp
 * @brief Exporta os registros de acomodações para um arquivo CSV.
 * 
 * Gera um arquivo CSV contendo os registros do array de acomodações.
 * Inclui uma barra de progresso para acompanhar a exportação.
 * 
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <fstream>   // Manipulação de arquivos
#include "utils.h"   // Estrutura acomodacoes
#include <unistd.h>  // Função sleep()

using namespace std;

/**
 * @brief Exporta os registros de acomodações para um arquivo CSV.
 * 
 * Gera um arquivo CSV contendo os registros do array de acomodações.
 * Inclui uma barra de progresso para acompanhar a exportação.
 * 
 * @param registros Ponteiro para o array dinâmico de registros de acomodações.
 * @param tamanhoAtual Número de registros atualmente armazenados.
 * @param nomeArquivo Nome do arquivo CSV onde os dados serão exportados.
 */
void exportarParaCSV(acomodacoes* registros, int tamanhoAtual, const string& nomeArquivo) 
{
    if (tamanhoAtual == 0) 
    {
        cout << "Nenhum dado para exportar." << endl;
        return;
    }

    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) 
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    // Escreve o cabeçalho do CSV
    arquivo << "ID, Nome, Preco, Minimo de noites\n";

    // Escreve os dados no arquivo CSV com barra de progresso
    for (int i = 0; i < tamanhoAtual; i++) 
    {
        arquivo << registros[i].id << ","
                << registros[i].name << ","
                << registros[i].price << ","
                << registros[i].minimum_nights << "\n";

        // Atualiza a barra de progresso
        exibirBarraCarregamento(i + 1, tamanhoAtual);
    }

    arquivo.close();
    cout << "Exportação concluída com sucesso para " << nomeArquivo << endl;
    sleep(2);
}
