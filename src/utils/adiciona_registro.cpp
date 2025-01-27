#include <iostream>
#include "utils.h"
#include <string>  // Para manipulação de strings (std::string)

using namespace std;

int adicionarRegistro(acomodacoes* registros, int& tamanhoAtual, int capacidadeMax) {
    if (tamanhoAtual >= capacidadeMax) {
        cout << "Capacidade máxima alcançada. Não é possível adicionar mais registros." << endl;
        return -1;  // Não há mais espaço
    }

    cout << "Adicionando um novo registro:" << endl;

    // Solicitar dados para o novo registro
    cout << "ID: ";
    long long int id;
    cin >> id;  // Usando cin para entrada
    registros[tamanhoAtual].id = id;

    cout << "Nome: ";
    string nome;
    cin.ignore();  // Ignora o '\n' deixado pelo cin anterior
    getline(cin, nome);  // Usa getline para ler o nome
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
    return 0;  // Sucesso
}
