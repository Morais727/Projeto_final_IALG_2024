/**
 * @file carregarBinario.cpp
 * @author Marcos Morais
 * @date 03/02/2025
 * @brief Carrega os registros de acomodações a partir de um arquivo binário.
 * 
 * Se o arquivo binário não for encontrado, um novo conjunto de registros será criado.
 * Se o arquivo estiver corrompido, os dados não serão carregados e um novo espaço será alocado.
 * A função utiliza alocação dinâmica para armazenar os registros, garantindo flexibilidade para
 * adicionar novos registros posteriormente.
 */

#include <iostream>
#include <fstream>   
#include "utils.h"
#include <string>
#include <ncurses.h>

using namespace std;

/**
 * @brief Carrega os registros de acomodações a partir de um arquivo binário.
 * 
 * Se o arquivo binário não existir, a função inicializa um novo array dinâmico.
 * Se o arquivo estiver corrompido, os dados não serão carregados e um novo espaço será alocado.
 * A função utiliza alocação dinâmica para armazenar os registros.
 * 
 * @param registros Ponteiro para o array dinâmico de registros.
 * @param tamanhoAtual Número de registros carregados.
 * @param capacidade Capacidade total alocada para armazenar os registros.
 * @param nomeArquivo Nome do arquivo binário a ser lido.
 */
void carregarBinario(acomodacoes*& registros, int& tamanhoAtual, int& capacidade, const string& nomeArquivo) 
{
    ifstream arquivo(nomeArquivo, ios::binary);  // Abre o arquivo em modo binário
    
    if (!arquivo.is_open()) 
    {
        cout << "Arquivo binário não encontrado. Criando novo..." << endl;
        tamanhoAtual = 0;
        capacidade = 10;
        registros = new acomodacoes[capacidade];  
        return;
    }

    // Ler quantidade de registros válidos
    arquivo.read(reinterpret_cast<char*>(&tamanhoAtual), sizeof(int));

    // Verifica se a leitura foi bem-sucedida
    if (!arquivo || tamanhoAtual <= 0 || tamanhoAtual > 1000000)
    { 
        cout << "Erro: Arquivo binário corrompido ou com dados inválidos." << endl;
        tamanhoAtual = 0;
        capacidade = 10;
        registros = new acomodacoes[capacidade];  
        arquivo.close();
        return;
    }

    // Ajustar capacidade dinamicamente para permitir novas inserções
    capacidade = tamanhoAtual + 10;

    // Evita vazamento de memória, liberando o espaço anterior antes de alocar um novo
    delete[] registros;
    registros = new acomodacoes[capacidade];

    // Ler registros do arquivo
    int lido = 0;
    while (lido < tamanhoAtual) 
    {
        // Lê até 1024 registros por vez para evitar sobrecarga
        int tamanhoBloco = min(tamanhoAtual - lido, 1024);
        arquivo.read(reinterpret_cast<char*>(registros + lido), tamanhoBloco * sizeof(acomodacoes));
        lido += arquivo.gcount() / sizeof(acomodacoes);  // Atualiza a quantidade de registros lidos
    }

    // Verificar se a leitura foi bem-sucedida
    if (!arquivo) 
    {
        cout << "Erro ao ler os registros do arquivo binário." << endl;
        delete[] registros;
        capacidade = 10;
        registros = new acomodacoes[capacidade];  
        tamanhoAtual = 0;
    }

    arquivo.close();
}
