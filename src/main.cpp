#include <iostream>
#include <unistd.h>  // Para usar usleep

#include "utils/utils.h"

using namespace std;

void clearConsole() 
{
    cout << "\033[2J\033[1;1H"; // Sequência ANSI para limpar a tela
}

int selecionaMenu(int numMenu)
{   
    switch (numMenu)
    {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;  
        case 4:
            return 4;  
        default:
            cout << "Opção inválida" << endl;
            return 0;  
    }
}

int main()
{
    clearConsole();

    bool executa = true;
    int numMenu = 0;

    printBanner();

    acomodacoes* registros = nullptr;  // Ponteiro para armazenar o array dinâmico
    int tamanhoAtual = 0;  // Número de registros armazenados

    // Chamar a função leituraCSV e verificar o retorno
    if (leituraCSV("saida1234.csv", registros, tamanhoAtual) == 0) 
    { 
        cout<<"ok";
        // ordenacaoBase(registros, tamanhoAtual);
    } 
    else 
    {
        cout << "Erro ao ler o arquivo CSV." << endl;
    }

    // Limpeza do console e exibição do menu
    clearConsole();
    printMenu1();
    
    while (executa == true)
    {  
        cin >> numMenu;
        int menu = selecionaMenu(numMenu);

        if (menu == 1)
        {
            clearConsole();
            menuImprime(registros, tamanhoAtual);
        }
        else if (menu == 2)
        {
            // executa = false;
            clearConsole();
            cout << "Selecionou alteração e remoção" << endl;
        }
        else if (menu == 3)
        {
            // executa = false;
            clearConsole();
            cout << "Selecionou cadastro de novos registros" << endl;
        }
        else if (menu == 4)
        {
            executa = false;
            cout << "Saindo..." << endl;
        }
    }

    // Liberar a memória alocada
    delete[] registros;

    return 0;
}
