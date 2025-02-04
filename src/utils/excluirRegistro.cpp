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

using namespace std;

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
    int id;
    
    // Solicita o ID do usuário
    cout << "Informe o ID do registro a ser excluído: ";
    if (!(cin >> id))  // Verifica se a entrada é válida
    {
        cout << "Entrada inválida! Certifique-se de inserir um número válido.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }

    bool encontrado = false;
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
                return -1;
            }

            // Desloca os registros subsequentes para "remover" o registro excluído
            for (int j = i; j < tamanhoAtual - 1; j++) 
            {
                registros[j] = registros[j + 1];
            }

            tamanhoAtual--;  // Decrementa o número de registros
            cout << "Registro excluído com sucesso." << endl;

            // Reorganizar os IDs após a exclusão
            cout << "Reorganizando os indices." << endl;
            reorganizarIDs(registros, tamanhoAtual);

            // Atualiza o arquivo binário com os registros restantes
            if (tamanhoAtual > 0)
            {
                ofstream arquivoBin(nomeArquivo, ios::binary | ios::trunc);
                if (!arquivoBin) 
                {
                    cout << "Erro ao abrir o arquivo binário para escrita!" << endl;
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
            }

            return 0;  // Sucesso
        }
    }

    // Caso o ID não seja encontrado
    cout << "ID não encontrado!" << endl;
    return -1;  
}
