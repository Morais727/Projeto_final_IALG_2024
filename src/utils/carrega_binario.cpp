#include <iostream>
#include <fstream>   
#include "utils.h"
#include <string> 

using namespace std;

void carregarBinario(acomodacoes*& registros, int& tamanhoAtual, int& capacidade, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        // Arquivo não existe, inicia vazio
        cout << "Arquivo binário não encontrado. Criando novo..." << endl;
        tamanhoAtual = 0;  // Garante que não há registros inválidos
        capacidade = 10;
        registros = new acomodacoes[capacidade];  
        return;
    }

    // Ler quantidade de registros válidos
    arquivo.read(reinterpret_cast<char*>(&tamanhoAtual), sizeof(int));

    // Verificar se a leitura foi bem-sucedida
    if (!arquivo || tamanhoAtual < 0 || tamanhoAtual > 1000000) { 
        cout << "Erro: Arquivo binário corrompido ou com dados inválidos." << endl;
        tamanhoAtual = 0;
        capacidade = 10;  // Redefine a capacidade para um valor inicial seguro
        registros = new acomodacoes[capacidade];  
        return;
    }

    // Ajustar a capacidade se necessário
    if (tamanhoAtual > capacidade) {
        capacidade = tamanhoAtual + 10;
        
        // Evita deletar memória não alocada
        if (registros != nullptr) {  
            delete[] registros;
        }

        registros = new acomodacoes[capacidade];
    }

    // Ler registros
    arquivo.read(reinterpret_cast<char*>(registros), tamanhoAtual * sizeof(acomodacoes));

    // Verificar se a leitura foi bem-sucedida
    if (!arquivo) {
        cout << "Erro ao ler os registros do arquivo binário." << endl;
        delete[] registros;
        capacidade = 10;
        registros = new acomodacoes[capacidade];  
        tamanhoAtual = 0;
    }

    arquivo.close();
}
