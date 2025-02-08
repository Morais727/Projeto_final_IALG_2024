/**
 * @file excluirRegistro.cpp
 * @brief Função para excluir registros de acomodações e atualizar o arquivo binário.
 * 
 * A exclusão é feita deslocando os registros subsequentes para substituir o registro removido.
 * O arquivo binário é regravado com os registros atualizados. Caso todos os registros sejam removidos,
 * o arquivo será deletado.
 * 
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <fstream>   // Para manipulação de arquivos
#include "utils.h"
#include <string>    // Para manipulação de strings (std::string)
#include <unistd.h>  // Para sleep()

using namespace std;

/**
 * @brief Verifica se uma string contém apenas números positivos.
 */
bool isPositiveNumber(const string& input) {
    if (input.empty()) return false;

    for (char c : input) {
        if (c < '0' || c > '9') return false;  // Só aceita dígitos de 0 a 9
    }

    return true;
}

/**
 * @brief Exclui um registro do array de acomodações e atualiza o arquivo binário.
 * 
 * O usuário informa um ID e, se encontrado, o registro é removido deslocando os subsequentes.
 * O arquivo binário é atualizado e, se não houver mais registros, o arquivo é deletado.
 * 
 * @param registros Ponteiro para o array dinâmico de registros de acomodações.
 * @param tamanhoAtual Referência para o número de registros atualmente armazenados.
 * @param nomeArquivo Nome do arquivo binário onde os registros são salvos.
 * @return int Retorna 0 em caso de sucesso e -1 se o ID não for encontrado ou houver erro na gravação.
 */
int excluirRegistro(acomodacoes* registros, int& tamanhoAtual, const string& nomeArquivo) 
{
    string entrada;
    int id;

    // Solicita o ID do usuário
    cout << "Informe o ID do registro a ser excluído (ou digite '0' para cancelar): ";
    cin >> entrada;

    // Valida a entrada antes de converter para inteiro
    if (!isPositiveNumber(entrada)) 
    {
        cout << "Entrada inválida! Certifique-se de inserir um número válido." << endl;
        sleep(2);
        clearConsole();
        return -1;
    }

    id = stoi(entrada);  // Converte para inteiro

    if (id == 0) 
    {
        cout << "Operação cancelada." << endl;
        sleep(2);
        clearConsole();
        return -1;
    }

    bool encontrado = false;  // Variável usada para verificar se o ID foi encontrado

    for (int i = 0; i < tamanhoAtual; i++) 
    {
        if (registros[i].id == id) 
        {
            encontrado = true;

            // Confirmação antes de excluir
            char confirmacao;
            cout << "Tem certeza que deseja excluir este registro? (S/N): ";
            cin >> confirmacao;
            if (tolower(confirmacao) != 's') 
            {
                cout << "Operação cancelada.\n";
                sleep(2);
                clearConsole();
                return -1;
            }

            // Desloca os registros subsequentes para "remover" o registro excluído
            for (int j = i; j < tamanhoAtual - 1; j++) 
            {
                registros[j] = registros[j + 1];
            }

            tamanhoAtual--;  // Decrementa o número de registros
            cout << "Registro excluído com sucesso." << endl;
            sleep(1);

            // Reorganizar os IDs após a exclusão
            cout << "Reorganizando os índices." << endl;
            reorganizarIDs(registros, tamanhoAtual);

            sleep(2);
            clearConsole();

            // Atualiza o arquivo binário com os registros restantes
            if (tamanhoAtual > 0) 
            {
                ofstream arquivoBin(nomeArquivo, ios::binary | ios::trunc);
                if (!arquivoBin) 
                {
                    cout << "Erro ao abrir o arquivo binário para escrita!" << endl;
                    sleep(2);
                    clearConsole();
                    return -1;
                }

                arquivoBin.write(reinterpret_cast<char*>(registros), tamanhoAtual * sizeof(acomodacoes));
                arquivoBin.close();
            } 
            else 
            {
                // Remove o arquivo se não houver mais registros
                remove(nomeArquivo.c_str());
                cout << "Todos os registros foram removidos. Arquivo deletado.\n";
                sleep(2);
                clearConsole();
            }

            return 0;  // Sucesso
        }
    }

    // Se chegou aqui e o ID não foi encontrado
    if (!encontrado)
    {
        cout << "ID não encontrado!" << endl;
        sleep(2);
        clearConsole();
        return -1;
    }

    return -1;
}