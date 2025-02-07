/**
 * @file main.cpp
 * @brief Implementação de funções para leitura, processamento e ordenação de dados de acomodações.
 * 
 * Este programa permite carregar, visualizar, modificar, excluir e exportar registros de acomodações
 * armazenados em arquivos CSV e binários. Utiliza menus interativos e funcionalidades de `ncurses`
 * para aprimorar a interface do usuário.
 * 
 * @author Marcos Morais
 * @date 03/02/2025
 */

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
    bool alteracoesNaoSalvas = false;
    const string arquivoBinario = "src/data/data.dat";

    bool executa = true;
    bool menu = true;

    while (executa) {  // Loop que permite voltar ao menu principal
        clearConsole();
        curs_set(0); // Esconde o cursor
        printBanner();

        acomodacoes* registros = nullptr;  // Ponteiro para armazenar o array dinâmico
        
        int tamanhoAtual = 0;  // Número de registros armazenados
        int capacidade = 10;  // Tamanho inicial do array dinâmico

        // Carregar dados do arquivo binário (se existir)
        carregarBinario(registros, tamanhoAtual, capacidade, arquivoBinario);
        
        // Limpeza do console e exibição do menu
        clearConsole();
        
        while (menu) 
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
                alteracoesNaoSalvas = true;
                alteraRegistro(registros, tamanhoAtual, arquivoBinario);
            }
            else if (numMenu == 3)
            {
                clearConsole();
                alteracoesNaoSalvas = true;
                excluirRegistro(registros, tamanhoAtual, arquivoBinario);
            }
            else if (numMenu == 4)
            {
                clearConsole();
                int capacidadeMax = 100000;  // Capacidade máxima de registros
                alteracoesNaoSalvas = true;
                int escolha = printSubMenu3();
                if (escolha == 1)
                {    
                    string nome_arquivo;  // Nome do arquivo a ser lido
                    cout << "Digite o nome do arquivo CSV:" << endl;
                    cin >> nome_arquivo;
                    if (nome_arquivo == " ")
                    {
                        cout << "Nome do arquivo inválido!" << endl;
                        sleep(2);
                        clearConsole();
                    }
                    else if (leituraCSV(nome_arquivo, registros, tamanhoAtual) == 0)
                    {
                        cout << "Arquivo carregado com sucesso!" << endl;
                        sleep(2);
                        clearConsole();
                    }
                    else
                    {
                        cout << "Erro ao carregar o arquivo!" << endl;
                        sleep(2);
                        clearConsole();
                    }
                }
                else if (escolha == 2) 
                {
                    adicionarRegistro(registros, tamanhoAtual,  capacidadeMax,  arquivoBinario);
                }   
                    
            }
            else if (numMenu == 5)
            {
                clearConsole();
                int choice = printSubMenu2();
                if (choice == 1)
                {
                    string nomeArquivo;
                    cout << "Digite o nome do arquivo a ser exportado: ";
                    cin >> nomeArquivo;
                    exportarParaCSV(registros, tamanhoAtual, nomeArquivo);
                }
                else if (choice == 2)
                {
                    exportarParaCSV(registros, tamanhoAtual, "dados.csv");
                }
                
            }
            else if (numMenu == 6)
            {
                if (alteracoesNaoSalvas) 
                {
                    cout << "Deseja salvar as alterações antes de sair? (S/N): "<< endl;
                    cout << "Não será possível desfazer as alterações." << endl;
                    char escolha;
                    cin >> escolha;
                    if (toupper(escolha) == 'S') 
                    {
                        salvarBinario(registros, tamanhoAtual, arquivoBinario);
                        cout << "Alterações salvas com sucesso!" << endl;
                        sleep(1);
                        cout << "Até mais!" << endl;
                        sleep(2);
                        clearConsole();
                    }
                }   
                executa = false;  // Termina a execução do programa               
                menu = false;
            }
        }
        // Liberar a memória alocada
        delete[] registros;
    }
    return 0;
}
