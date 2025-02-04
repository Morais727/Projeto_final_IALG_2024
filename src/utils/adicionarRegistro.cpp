/**
 * @file adicionarRegistro.cpp
 * @brief Implementação da função para adicionar registros de acomodações.
 *
 * Esta função permite adicionar um novo registro de acomodação a um array dinâmico,
 * armazenando as informações fornecidas pelo usuário e atualizando um arquivo binário.
 *
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <fstream>   // Para manipulação de arquivos
#include "utils.h"
#include <string>    // Para manipulação de strings (std::string)
#include <cstring>   // Para manipulação de C-strings (strncpy)

using namespace std;

/**
 * @brief Adiciona um novo registro de acomodação ao array e atualiza o arquivo binário.
 *
 * A função solicita os dados da nova acomodação ao usuário, armazena no array `registros`
 * e escreve os dados atualizados no arquivo binário especificado. 
 * Se a capacidade máxima for atingida, a função não adiciona o registro.
 *
 * @param registros Ponteiro para o array de registros de acomodações.
 * @param tamanhoAtual Referência ao número atual de registros armazenados.
 * @param capacidadeMax Número máximo de registros que podem ser armazenados no array.
 * @param nomeArquivo Nome do arquivo binário onde os registros são armazenados.
 * @return int Retorna `0` em caso de sucesso ou `-1` se a capacidade for excedida ou ocorrer erro no arquivo.
 */
int adicionarRegistro(acomodacoes* registros, int& tamanhoAtual, int capacidadeMax, const string& nomeArquivo) 
{
    // Verifica se há espaço para um novo registro
    if (tamanhoAtual >= capacidadeMax) 
    {
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

    // Copia o nome para o array de caracteres da estrutura, garantindo terminação nula
    strncpy(registros[tamanhoAtual].name, nome.c_str(), sizeof(registros[tamanhoAtual].name) - 1);
    registros[tamanhoAtual].name[sizeof(registros[tamanhoAtual].name) - 1] = '\0'; 

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
    if (!arquivoBin) 
    {
        cout << "Erro ao abrir o arquivo binário para escrita!" << endl;
        return -1;
    }

    // Escrever todos os registros no arquivo binário
    arquivoBin.write(reinterpret_cast<char*>(registros), tamanhoAtual * sizeof(acomodacoes));
    arquivoBin.close();

    return 0;  // Sucesso
}