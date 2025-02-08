/**
 * @file alteraRegistro.cpp
 * @brief Função para alterar um registro existente e atualizar o arquivo binário.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <fstream>   // Para manipulação de arquivos
#include <string>    // Para manipulação de strings (std::string)
#include "utils.h"   // Para a definição da estrutura acomodacoes
#include <cstring>   // Para usar getline() corretamente
#include <unistd.h> 

using namespace std;

/**
 * @brief Altera um registro existente no array e atualiza o arquivo binário.
 * 
 * O usuário informa o ID do registro que deseja alterar. Se encontrado, os dados são exibidos 
 * e podem ser modificados. As alterações são salvas no arquivo binário.
 * 
 * @param registros Ponteiro para o array de registros de acomodações.
 * @param tamanhoAtual Número atual de registros armazenados.
 * @param nomeArquivo Nome do arquivo binário onde os registros são armazenados.
 * @return int Retorna `0` se a alteração for bem-sucedida ou se o usuário cancelar a operação, e `-1` se ocorrer um erro na escrita do arquivo.
 */
int alteraRegistro(acomodacoes* registros, int tamanhoAtual, const string& nomeArquivo) 
{
    char entrada[20];  // Buffer para entrada do usuário
    int numero;  // Variável auxiliar para conversão de string para int
    int id;  // ID do registro a ser alterado

    while (true) 
    {
        
        cout << "Informe o ID do registro a ser alterado (ou digite '0' para cancelar): " << endl;

        cin >> entrada;
        if (isNumber(entrada)) {
            numero = atoi(entrada);  // Converte para int
            id = numero;
        } 
        else 
        {
            cout << "Entrada inválida! Voltando ao menu inicial." << endl;
            sleep(2);
            return -1;
        }

        // Permitir que o usuário cancele a operação
        if (id == 0) 
        {
            cout << "Operação cancelada. Voltando ao menu anterior." << endl;
            sleep(2);
            return 0;
        }

        bool encontrado = false;
        char altera;
        

        // Buscar o registro pelo ID
        for (int i = 0; i < tamanhoAtual; i++) 
        {
            if (registros[i].id == id) 
            {
                encontrado = true;
                cout << "Registro encontrado:" << endl;
                cout << "Nome: " << registros[i].name << endl;
                cout << "Quartos: " << registros[i].bedrooms << endl;
                cout << "Banheiros: " << registros[i].bathrooms << endl;
                cout << "Mínimo de noites: " << registros[i].minimum_nights << endl;
                cout << "Estrelas: " << registros[i].review_scores_rating << endl;
                cout << "Diária: " << registros[i].price << endl << endl << endl << endl;

                // Solicitar novas informações do usuário
                cout << "Alterar Nome? (atualmente: " << registros[i].name << ") [S/N]: ";
                cin >> altera;
                if (tolower(altera) == 's') 
                {
                    cout << "Digite o novo nome: ";
                    cin.ignore();  // Limpar o buffer do cin
                    cin.getline(registros[i].name, sizeof(registros[i].name)); // Permite entrada com espaços
                }

                cout << "Alterar Quartos? (atualmente: " << registros[i].bedrooms << ") [S/N]: ";
                cin >> altera;
                if (tolower(altera) == 's') 
                {
                    cout << "Digite a nova quantidade: ";
                    cin >>  entrada;
                    
                    if (isNumber(entrada)) {
                        numero = atoi(entrada);  // Converte para int
                        registros[i].bedrooms = numero;
                    } 
                    else 
                    {
                        cout << "Entrada inválida! Voltando ao menu inicial." << endl;
                        sleep(2);
                        return -1;
                    }
                    
                   
                }
                
                cout << "Alterar Banheiros? (atualmente: " << registros[i].bathrooms << ") [S/N]: ";
                cin >> altera;
                if (tolower(altera) == 's') 
                {
                    cout << "Digite a nova quantidade: ";
                    cin >>  entrada;
                    
                    if (isNumber(entrada)) {
                        numero = atoi(entrada);  // Converte para int
                        registros[i].bathrooms = numero;
                    } 
                    else 
                    {
                        cout << "Entrada inválida! Voltando ao menu inicial." << endl;
                        sleep(2);
                        return -1;
                    }
                }
                
                cout << "Alterar Mínimo de noites? (atualmente: " << registros[i].minimum_nights << ") [S/N]: ";
                cin >> altera;
                if (tolower(altera) == 's') 
                {   
                    cout << "Digite a nova quantidade: ";
                    cin >>  entrada;
                    
                    if (isNumber(entrada)) {
                        numero = atoi(entrada);  // Converte para int
                        registros[i].minimum_nights = numero;
                    } 
                    else 
                    {
                        cout << "Entrada inválida! Voltando ao menu inicial." << endl;
                        sleep(2);
                        return -1;
                    }
                }
                
                cout << "Alterar Estrelas? (atualmente: " << registros[i].review_scores_rating << ") [S/N]: ";
                cin >> altera;
                if (tolower(altera) == 's') 
                {   
                    cout << "Digite a nova quantidade: ";
                    cin >>  entrada;
                    
                    if (isNumber(entrada)) {
                        numero = atoi(entrada);  // Converte para int
                        registros[i].review_scores_rating = numero;
                    } 
                    else 
                    {
                        cout << "Entrada inválida! Voltando ao menu inicial." << endl;
                        sleep(2);
                        return -1;
                    }
                }
                
                cout << "Alterar Diária? (atualmente: " << registros[i].price << ") [S/N]: ";
                cin >> altera;
                if (tolower(altera) == 's') 
                {
                    cout << "Digite a nova quantidade: ";
                    cin >>  entrada;
                    
                    if (isNumber(entrada)) {
                        numero = atoi(entrada);  // Converte para int
                        registros[i].price = numero;
                    } 
                    else 
                    {
                        cout << "Entrada inválida! Voltando ao menu inicial." << endl;
                        sleep(2);
                        return -1;
                    }
                }

                cout << "Registro alterado com sucesso!" << endl;
                return 0;
            }
        }

        // Caso o ID não seja encontrado
        if (!encontrado) 
        {
            cout << "ID não encontrado!" << endl;
        }
    }
}
