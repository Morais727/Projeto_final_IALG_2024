#include <iostream>
#include "utils.h"
#include <string>  // Para manipulação de strings (std::string)

using namespace std;

int excluirRegistro(acomodacoes* registros, int& tamanhoAtual) {
    int id;
    
    // Exibe a mensagem para o usuário
    cout << "Informe o ID do registro a ser excluído: ";
    
    // Lê a entrada do ID
    cin >> id;  // Lê o ID do registro a ser excluído

    bool encontrado = false;
    for (int i = 0; i < tamanhoAtual; i++) {
        if (registros[i].id == id) {
            encontrado = true;

            // Desloca os registros subsequentes
            for (int j = i; j < tamanhoAtual - 1; j++) {
                registros[j] = registros[j + 1];
            }

            tamanhoAtual--;  // Decrementa o número de registros
            cout << "Registro excluído com sucesso." << endl;
            return 0;  // Sucesso
        }
    }

    if (!encontrado) {
        cout << "ID não encontrado!" << endl;
        return -1;  // ID não encontrado
    }

    return 0;
}
