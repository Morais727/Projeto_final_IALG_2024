#include <iostream>
#include <unistd.h> //sleep

#include "utils/utils.h"

using namespace std;

void clearConsole() {
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
    int tamanhoAtual = 1000;  // Número de registros armazenados

    // Chamar a função leituraCSV
    leituraCSV("saida1234.csv", registros, tamanhoAtual);

    // Exibir os registros
    for (int i = 0; i < tamanhoAtual; i++) {
        cout << "ID: " << registros[i].id << ", Nome: " << registros[i].name << endl;
    }

    // Liberar a memória alocada
    delete[] registros;

    // usleep(9000000);

    // clearConsole();
    printMenu1();

    cin >> numMenu;

    selecionaMenu(numMenu);
    
   return 0;
}