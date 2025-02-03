#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <exception>
#include "utils.h"
#include <iomanip>  // Para manipulação de saída (setw)
#include <unistd.h>  // Para usar usleep
#include <cstdlib>
#include <ncurses.h> // Visualizações sofisticadas

using namespace std;

// Função para inicializar o ncurses
void inicializaNcurses() {
    initscr();           // Inicia o modo ncurses
    noecho();            // Evita que os inputs do teclado apareçam no terminal
    cbreak();            // Lê entrada imediatamente, sem esperar Enter
    keypad(stdscr, TRUE); // Habilita teclas como as setas
    curs_set(0);         // Esconde o cursor
}

// Função para finalizar o ncurses
void finalizaNcurses() {
    endwin();
}

int imprimeValores(acomodacoes* registros, int tamanhoAtual, int tamanhoInicial, int tamanhoFinal) {
    // Inicializar ncurses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Dimensões da tela
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // Cabeçalhos formatados
    const int id_width = 8;
    const int name_width = 100;
    const int bedrooms_width = 15;
    const int bathrooms_width = 15;
    const int minimum_nights_width = 25;
    const int review_width = 15;
    const int price_width = 10;

    bool running = true;
    int highlight = 0;

    int escolha = -1;

    while (running) {
        clear();

        // Imprimir cabeçalhos
        mvprintw(0, 0, "%-*s%-*s%-*s%-*s%-*s%-*s%-*s", id_width, "ID", name_width, "Nome", bedrooms_width, "Quartos",
                 bathrooms_width, "Banheiros", minimum_nights_width, "Mínimo de noites", review_width, "Estrelas", price_width, "Diária");

        // Linha separadora
        mvhline(1, 0, '-', id_width + name_width + bedrooms_width + bathrooms_width + minimum_nights_width + review_width + price_width);

        // Imprimir os valores formatados
        for (int i = 0; i < (tamanhoFinal - tamanhoInicial); i++) {
            int idx = tamanhoInicial + i;
            if (idx >= tamanhoAtual) break;

            // Montar string formatada
            stringstream ss;
            ss << left << setw(id_width) << registros[idx].id
               << setw(name_width) << registros[idx].name
               << setw(bedrooms_width) << registros[idx].bedrooms
               << setw(bathrooms_width) << registros[idx].bathrooms
               << setw(minimum_nights_width) << registros[idx].minimum_nights
               << fixed << setprecision(2)<< setw(review_width) << registros[idx].review_scores_rating
               << right << fixed << setprecision(2) << setw(price_width) << registros[idx].price;

            if (i == highlight) {
                attron(A_REVERSE);
                mvprintw(2 + i, 0, "%s", ss.str().c_str());                attroff(A_REVERSE);
            } else {
                mvprintw(2 + i, 0, "%s", ss.str().c_str());            }
        }

        // Rodapé
        mvprintw(rows - 8, 0, tamanhoFinal < tamanhoAtual ? "Mostrando %d-%d de %d registros" : "Mostrando %d-%d de %d registros", tamanhoInicial, tamanhoFinal, tamanhoAtual);
        mvprintw(rows - 3, 0, "Página anterior (B)    --  Próxima página (N)    --  Voltar (V)    --  Filtrar (F)");
        mvprintw(rows - 2, 0, "Use as setas para navegar e Enter para selecionar.");

        // Atualizar tela
        refresh();

        // Lidar com entrada do usuário
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if (highlight > 0) highlight--;
                break;
            case KEY_DOWN:
                if (highlight < (tamanhoFinal - tamanhoInicial - 1) && (tamanhoInicial + highlight + 1 < tamanhoAtual)) {
                    highlight++;
                }
                break;
            case 'b': // Página anterior
                if (tamanhoInicial > 0) {
                    tamanhoInicial -= 35;
                    tamanhoFinal -= 35;
                    highlight = 0;
                }
                break;
            case 'n': // Próxima página
                if (tamanhoFinal < tamanhoAtual) {
                    tamanhoInicial += 35;
                    tamanhoFinal += 35;
                    highlight = 0;
                }
                break;
            case 'v': // Voltar
                endwin(); // Finalizar ncurses
                return -10;
            case 'f': // Filtro
                endwin();                
                return -20;
            case 10: // Enter
                escolha = highlight;
                return (escolha+tamanhoInicial)+1;
            default:
                break;
        }
    }

    // Finalizar ncurses
    endwin();

    return 0;
}

