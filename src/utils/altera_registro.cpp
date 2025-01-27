#include <iostream>
#include "utils.h"
#include <string>  // Para manipulação de strings (std::string)

using namespace std;

int alteraRegistro(acomodacoes* registros, int tamanhoAtual) {
    // Exibe os registros
    int id;
    cout << "Informe o ID do registro a ser alterado: " << endl;
    cin >> id;  // Lê o ID do registro a ser alterado

    bool encontrado = false;
    for (int i = 0; i < tamanhoAtual; i++) {
        if (registros[i].id == id) {
            encontrado = true;
            cout << "Registro encontrado:" << endl;
            cout << "Nome: " << registros[i].name << endl;
            cout << "Quartos: " << registros[i].bedrooms << endl;
            cout << "Banheiros: " << registros[i].bathrooms << endl;
            cout << "Mínimo de noites: " << registros[i].minimum_nights << endl;
            cout << "Estrelas: " << registros[i].review_scores_rating << endl;
            cout << "Diária: " << registros[i].price << endl;

            // Solicitar alteração dos campos
            cout << "Alterar Nome (atualmente: " << registros[i].name << "): ";
            cin.ignore();  // Ignora o '\n' deixado pelo cin anterior
            getline(cin, registros[i].name);  // Usa getline para ler a string

            cout << "Alterar Quartos (atualmente: " << registros[i].bedrooms << "): ";
            cin >> registros[i].bedrooms;

            cout << "Alterar Banheiros (atualmente: " << registros[i].bathrooms << "): ";
            cin >> registros[i].bathrooms;

            cout << "Alterar Mínimo de noites (atualmente: " << registros[i].minimum_nights << "): ";
            cin >> registros[i].minimum_nights;

            cout << "Alterar Estrelas (atualmente: " << registros[i].review_scores_rating << "): ";
            cin >> registros[i].review_scores_rating;

            cout << "Alterar Diária (atualmente: " << registros[i].price << "): ";
            cin >> registros[i].price;

            return 0;  // Sucesso
        }
    }

    if (!encontrado) {
        cout << "ID não encontrado!" << endl;
        return -1;  // ID não encontrado
    }

    return 0;
}
