#include <iostream>
#include <unistd.h>  // Para usar usleep
#include <ncurses.h>  // Para as funções ncurses (clear, mvprintw, getch)

#include "utils/utils.h"

using namespace std;

void clearConsole() 
{
    cout << "\033[2J\033[1;1H"; // Sequência ANSI para limpar a tela
}


int main()
{
    bool executa = true;

    while (executa) {  // Loop que permite voltar ao menu principal
        clearConsole();
        curs_set(0); // Esconde o cursor
        printBanner();

        acomodacoes* registros = nullptr;  // Ponteiro para armazenar o array dinâmico
        int tamanhoAtual = 0;  // Número de registros armazenados

        // Chamar a função leituraCSV e verificar o retorno
        if (leituraCSV("dados_limpos.csv", registros, tamanhoAtual) == 0) 
        { 
            cout<<"ok";
            // ordenacaoBase(registros, tamanhoAtual);
        } 
        else 
        {
            cout << "Erro ao ler o arquivo CSV." << endl;
            break;  // Se não conseguir ler o arquivo, sai do loop
        }

        // Limpeza do console e exibição do menu
        clearConsole();
        
        while (true) 
        {
            curs_set(0); // Esconde o cursor
            int numMenu = printMenu1();

            if (numMenu == 1)
            {
                clearConsole();
                menuImprime(registros, tamanhoAtual);  // Chama o menu interativo
            }
            else if (numMenu == 2)
            {
                clearConsole();
                alteraRegistro(registros, tamanhoAtual);
            }
            else if (numMenu == 3)
            {
                clearConsole();
                excluirRegistro(registros, tamanhoAtual);
            }
            else if (numMenu == 4)
            {
                clearConsole();
                int capacidadeMax = 100000;  // Capacidade máxima de registros
                adicionarRegistro(registros, tamanhoAtual, capacidadeMax);
            }
            else if (numMenu == 5)
            {
                executa = false;  // Termina a execução do programa               
                break;  // Sai do loop interno
            }
        }

        // Liberar a memória alocada
        delete[] registros;
    }

    return 0;
}

