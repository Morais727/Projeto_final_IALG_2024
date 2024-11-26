#include <iostream>
#include <unistd.h>  // Para usar usleep

#include "utils/utils.h"

using namespace std;

void clearConsole() 
{
    cout << "\033[2J\033[1;1H"; // Sequência ANSI para limpar a tela
}

void selecionaMenu(int numMenu)
{   
    switch (numMenu)
    {
        case 1:
            cout << "Selecionou busca de registros" << endl;
            break;
        case 2:
            cout << "Selecionou alteração e remoção" << endl;
            break;
        case 3:
            cout << "Selecionou cadastro de novos registros" << endl;
            break;  
        case 4:
            cout << "Saindo..." << endl;
            break;  
        default:
            cout << "Opção inválida" << endl;
            break;  
    }
}

int main()
{
    int numMenu;

    printBanner();

    acomodacoes* registros = nullptr;  // Ponteiro para armazenar o array dinâmico
    int tamanhoAtual = 0;  // Número de registros armazenados

    // Chamar a função leituraCSV e verificar o retorno
    if (leituraCSV("saida1234.csv", registros, tamanhoAtual) == 0) 
    {
        ordenacaoBase(registros, tamanhoAtual);

        // Exibir os registros se a leitura foi bem-sucedida
        // cout << "Total de registros lidos: " << tamanhoAtual << endl;
        // for (int i = 0; i < tamanhoAtual; i++) 
        // {
        //     cout << "ID: " << registros[i].id << ", Nome: " << registros[i].name << endl;
        // }
    } 
    else 
    {
        cout << "Erro ao ler o arquivo CSV." << endl;
    }

    // Limpeza do console e exibição do menu
    clearConsole();
    printMenu1();

    cin >> numMenu;
    selecionaMenu(numMenu);
    
    // Liberar a memória alocada
    delete[] registros;

    return 0;
}
