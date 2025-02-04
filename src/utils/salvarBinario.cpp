/**
 * @file salvarBinario.cpp
 * @brief Implementação de uma função para salvar dados de acomodações em um arquivo binário.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <fstream>   
#include "utils.h"
#include <string> 

using namespace std;

/**
 * @brief Salva os dados das acomodações em um arquivo binário.
 * @param registros Um array de estruturas `acomodacoes` contendo os dados a serem salvos.
 * @param tamanhoAtual O número de registros no array.
 * @param nomeArquivo O nome do arquivo binário onde os dados serão salvos.
 */
void salvarBinario(acomodacoes* registros, int tamanhoAtual, const string& nomeArquivo) 
{
    ofstream arquivo(nomeArquivo, ios::binary); // Abre o arquivo em modo binário
    if (!arquivo.is_open()) 
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    // Escreve o número de registros no arquivo
    arquivo.write(reinterpret_cast<char*>(&tamanhoAtual), sizeof(int));
    
    // Escreve os registros binários
    arquivo.write(reinterpret_cast<char*>(registros), tamanhoAtual * sizeof(acomodacoes));

    arquivo.close(); // Fecha o arquivo
}