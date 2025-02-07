/**
 * @file imprimeValores.cpp
 * @brief Implementação da função para exibir registros de acomodações em uma interface interativa.
 * @author Marcos Morais
 * @date 03/02/2025
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <exception>
#include "utils.h"
#include <iomanip>  // Para manipulação de saída (setw)
#include <unistd.h> // Para usar usleep
#include <cstdlib>
#include <ncurses.h> // Para visualizações sofisticadas

using namespace std;

/**
 * @brief Exibe os registros de acomodações em uma interface interativa utilizando ncurses.
 * 
 * Esta função exibe uma tabela formatada com os detalhes das acomodações, permitindo ao usuário
 * navegar pelos registros, alternar páginas e selecionar um item específico. A interface é construída
 * utilizando a biblioteca ncurses para proporcionar uma experiência interativa e sofisticada.
 * 
 * @param registros Ponteiro para o array de registros de acomodações.
 * @param tamanhoAtual Número total de registros disponíveis.
 * @param tamanhoInicial Índice do primeiro registro a ser exibido.
 * @param tamanhoFinal Índice do último registro a ser exibido.
 * 
 * @return int Código de retorno:
 * - ID do item selecionado (índice + 1).
 * - -10 para indicar que o usuário escolheu voltar.
 * - -20 para indicar que o usuário escolheu filtrar.
 * 
 * @details
 * - A função utiliza ncurses para criar uma interface interativa.
 * - Os registros são exibidos em uma tabela formatada com colunas para ID, nome, quartos, banheiros,
 *   mínimo de noites, avaliações e preço.
 * - O usuário pode navegar pelos registros usando as setas do teclado.
 * - É possível alternar entre páginas de resultados usando as teclas 'B' (anterior) e 'N' (próxima).
 * - A tecla 'V' permite ao usuário voltar ao menu anterior.
 * - A tecla 'F' permite ao usuário acessar o menu de filtros.
 * - A tecla 'Enter' seleciona o item destacado.
 * 
 * @note
 * - A função inicializa e finaliza o modo ncurses automaticamente.
 * - O cursor é ocultado durante a execução da função.
 * - A função retorna o índice do item selecionado ajustado para começar em 1 (em vez de 0).
 */
int imprimeValores(acomodacoes* registros, int tamanhoAtual, int tamanhoInicial, int tamanhoFinal) 
{
    // Inicializar ncurses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0); // Oculta o cursor

    // Dimensões da tela
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // Largura das colunas da tabela
    const int id_width = 8;
    const int name_width = 100;
    const int bedrooms_width = 15;
    const int bathrooms_width = 15;
    const int minimum_nights_width = 25;
    const int review_width = 15;
    const int price_width = 4;

    bool running = true; // Controla o loop principal
    int highlight = 0;   // Índice do item destacado
    int escolha = -1;    // Armazena a escolha do usuário

    while (running) 
    {
        clear(); // Limpa a tela

        // Imprimir cabeçalhos da tabela
        mvprintw(0, 0, "%-*s%-*s%-*s%-*s%-*s%-*s%-*s", id_width, "ID", name_width, "Nome", bedrooms_width, "Quartos",
                 bathrooms_width, "Banheiros", minimum_nights_width, "Mínimo de noites", review_width, "Estrelas", price_width, "    Diária");

        // Linha separadora
        mvhline(1, 0, '-', id_width + name_width + bedrooms_width + bathrooms_width + minimum_nights_width + review_width + price_width + 9);

        // Imprimir os valores formatados
        for (int i = 0; i < (tamanhoFinal - tamanhoInicial) && (tamanhoInicial + i) < tamanhoAtual; i++) 
        {
            int idx = tamanhoInicial + i;

            // Criar string formatada com os dados
            stringstream ss;
            ss << left << setw(id_width) << registros[idx].id
               << setw(name_width) << registros[idx].name
               << setw(bedrooms_width) << registros[idx].bedrooms
               << setw(bathrooms_width) << registros[idx].bathrooms
               << setw(minimum_nights_width) << registros[idx].minimum_nights
               << fixed << setprecision(2) << setw(review_width) << registros[idx].review_scores_rating
               << right << fixed << setprecision(2) << setw(price_width) << "$ " << registros[idx].price;

            // Destacar linha selecionada
            if (i == highlight) 
            {
                attron(A_REVERSE); // Inverte as cores para destacar
                mvprintw(2 + i, 0, "%s", ss.str().c_str());
                attroff(A_REVERSE);
            } 
            else 
            {
                mvprintw(2 + i, 0, "%s", ss.str().c_str());            
            }
        }

        // Exibir rodapé com informações e comandos
        mvprintw(rows - 8, 0, tamanhoFinal < tamanhoAtual ? "Mostrando %d-%d de %d registros" : "Mostrando %d-%d de %d registros", 
                 tamanhoInicial+1, tamanhoFinal, tamanhoAtual);
        mvprintw(rows - 3, 0, "Página anterior (B)    --  Próxima página (N)    --  Voltar ao menu anterior (V)    --  Filtrar (F)");
        mvprintw(rows - 2, 0, "Use as setas para navegar e Enter para selecionar.");

        // Atualizar tela
        refresh();

        // Capturar entrada do usuário
        int ch = getch();
        switch (ch) 
        {
            case KEY_UP:
                /// Move a seleção para cima
                if (highlight > 0) highlight--;
                break;

            case KEY_DOWN:
                /// Move a seleção para baixo, garantindo que esteja dentro dos limites
                if (highlight < (tamanhoFinal - tamanhoInicial - 1) && (tamanhoInicial + highlight + 1 < tamanhoAtual)) 
                {
                    highlight++;
                }
                break;

            case 'b': // Página anterior
                /// Volta para a página anterior (se possível)
                if (tamanhoInicial > 0) 
                {
                    tamanhoInicial -= 35;
                    tamanhoFinal -= 35;
                    highlight = 0;
                }
                break;

            case 'n': // Próxima página
                /// Avança para a próxima página (se possível)
                if (tamanhoFinal < tamanhoAtual) 
                {
                    tamanhoInicial += 35;
                    tamanhoFinal += 35;
                    highlight = 0;
                }
                break;

            case 'v': // Voltar
                /// Sai da função retornando -10
                endwin();
                return -10;

            case 'f': // Filtro
                /// Sai da função retornando -20 (sinalizando opção de filtro)
                endwin();
                return -20;

            case 10: // Enter (selecionar item)
                /// Retorna o índice do item selecionado
                escolha = highlight;
                return (escolha + tamanhoInicial) + 1;

            default:
                break;
        }
    }

    // Finalizar ncurses antes de sair
    endwin();

    return 0;
}