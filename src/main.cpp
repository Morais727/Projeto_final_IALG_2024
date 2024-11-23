#include <iostream>
#include <unistd.h> //sleep

#include "utils/utils.h"

using namespace std;

void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // Sequência ANSI para limpar a tela
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
    usleep(9000000);

    clearConsole();
    printMenu1();

    cin >> numMenu;

    selecionaMenu(numMenu);

    
   return 0;
}