#include <iostream>
#include <fstream>   // Para manipulação de arquivos
#include "utils.h"
#include <string>  // Para manipulação de strings (std::string)

using namespace std;

int adicionarRegistro(acomodacoes* registros, int& tamanhoAtual, int capacidadeMax, const string& nomeArquivo) {
    if (tamanhoAtual >= capacidadeMax) {
        cout << "Capacidade máxima alcançada. Não é possível adicionar mais registros." << endl;
        return -1;  // Não há mais espaço
    }

    cout << "Adicionando um novo registro:" << endl;

    // Solicitar dados para o novo registro
    cout << "ID: ";
    long long int id;
    cin >> id;
    registros[tamanhoAtual].id = id;

    cout << "Nome: ";
    string nome;
    cin.ignore();  // Ignora o '\n' deixado pelo cin anterior
    getline(cin, nome);
    registros[tamanhoAtual].name = nome;

    cout << "Quartos: ";
    cin >> registros[tamanhoAtual].bedrooms;

    cout << "Banheiros: ";
    cin >> registros[tamanhoAtual].bathrooms;

    cout << "Mínimo de noites: ";
    cin >> registros[tamanhoAtual].minimum_nights;

    cout << "Estrelas: ";
    cin >> registros[tamanhoAtual].review_scores_rating;

    cout << "Diária: ";
    cin >> registros[tamanhoAtual].price;

    // Atualiza o número de registros
    tamanhoAtual++;
    cout << "Novo registro adicionado com sucesso." << endl;

    // Abrir o arquivo binário para atualização
    ofstream arquivoBin(nomeArquivo, ios::binary | ios::trunc);
    if (!arquivoBin) {
        cout << "Erro ao abrir o arquivo binário para escrita!" << endl;
        return -1;
    }

    // Escrever todos os registros (incluindo o novo) no arquivo binário
    arquivoBin.write(reinterpret_cast<char*>(registros), tamanhoAtual * sizeof(acomodacoes));
    arquivoBin.close();

    return 0;  // Sucesso
}
