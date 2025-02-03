#include <iostream>
#include <fstream>   // Para manipulação de arquivos
#include <string>    // Para manipulação de strings (std::string)
#include "utils.h"   // Para a definição da estrutura acomodacoes
#include <cstring>   // Para usar strcpy()

using namespace std;

int alteraRegistro(acomodacoes* registros, int tamanhoAtual, const string& nomeArquivo) {
    while (true) {
        int id;
        cout << "Informe o ID do registro a ser alterado (ou digite '0' para cancelar): " << endl;
        cin >> id;

        if (id == 0) {
            cout << "Operação cancelada. Voltando ao menu anterior." << endl;
            return 0;
        }

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
                cin.ignore();  // Limpar o buffer do cin
                cin.getline(registros[i].name, sizeof(registros[i].name)); // Usar getline para ler com espaços
                
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
                
                // Abrir o arquivo binário para reescrita
                ofstream arquivoBin(nomeArquivo, ios::binary | ios::trunc);
                if (!arquivoBin) {
                    cout << "Erro ao abrir o arquivo binário para escrita!" << endl;
                    return -1;
                }

                // Escrever todos os registros alterados no arquivo binário
                arquivoBin.write(reinterpret_cast<char*>(registros), tamanhoAtual * sizeof(acomodacoes));
                arquivoBin.close();

                cout << "Registro alterado com sucesso! Alterações gravadas no arquivo binário." << endl;
                return 0;
            }
        }

        if (!encontrado) {
            cout << "ID não encontrado! Tente novamente ou digite '0' para cancelar." << endl;
        }
    }
}
