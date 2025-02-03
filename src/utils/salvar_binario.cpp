#include <iostream>
#include <fstream>   
#include "utils.h"
#include <string> 

using namespace std;

void salvarBinario(acomodacoes* registros, int tamanhoAtual, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    // Escreve o número de registros no arquivo
    arquivo.write(reinterpret_cast<char*>(&tamanhoAtual), sizeof(int));
    // Escreve os registros binários
    arquivo.write(reinterpret_cast<char*>(registros), tamanhoAtual * sizeof(acomodacoes));

    arquivo.close();
}