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


string removeEmojis(const string &input) 
{
    regex emojiRegex("[\\xF0-\\xF7][\\x80-\\xBF]{2,3}");
    return regex_replace(input, emojiRegex, "");
}

bool isNumber(const string &str) 
{
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

bool isFloat(const string &str) 
{
    istringstream iss(str);
    float temp;
    return (iss >> temp) && iss.eof();
}

int leituraCSV(string nomeArquivo, acomodacoes*& registros, int& tamanhoAtual) 
{
    ifstream arquivoInicial(nomeArquivo);

    if (!arquivoInicial.is_open()) 
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    int capacidade = 10;  // Tamanho inicial do array dinâmico
    tamanhoAtual = 0;  // Quantidade de registros armazenados
    registros = new acomodacoes[capacidade];  // Alocação inicial

    string linha;
    int linhaAtual = 0;
    int linhasProblematicas = 0;

    // Ignorar a primeira linha (cabeçalho)
    getline(arquivoInicial, linha);

    while (getline(arquivoInicial, linha)) 
    {
        linhaAtual++;
        linha = removeEmojis(linha);  // Remover emojis ou caracteres indesejados
        istringstream ss(linha);
        acomodacoes item;
        string temp;

        try 
        {
            // Processar ID
            getline(ss, temp, ',');
            item.id = isNumber(temp) ? stoll(temp) : 0;

            // Processar Nome
            getline(ss, item.name, ',');

            // Processar Host ID
            getline(ss, temp, ',');
            item.host_id = isNumber(temp) ? stoll(temp) : 0;

            // Processar Nome do Host
            getline(ss, item.host_name, ',');

            // Processar Host Since
            getline(ss, temp, ',');
            item.host_since = isNumber(temp) ? stoi(temp) : 0;

            // Processar Host Response Time
            getline(ss, item.host_response_time, ',');

            // Processar Host Response Rate
            getline(ss, temp, ',');
            item.host_response_rate = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Superhost
            getline(ss, temp, ',');
            item.host_is_superhost = (temp == "t" || temp == "f") ? temp[0] : 'f';

            // Processar Neighborhood Cleansed
            getline(ss, item.neighbourhood_cleansed, ',');

            // Processar Neighborhood Group Cleansed
            getline(ss, item.neighbourhood_group_cleansed, ',');

            // Processar Latitude
            getline(ss, temp, ',');
            item.latitude = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Longitude
            getline(ss, temp, ',');
            item.longitude = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Property Type
            getline(ss, item.property_type, ',');

            // Processar Room Type
            getline(ss, item.room_type, ',');

            // Processar Accommodates
            getline(ss, temp, ','); 
            item.accommodates = isNumber(temp) ? stoi(temp) : 0;

            // Processar Bathrooms
            getline(ss, temp, ','); 
            item.bathrooms = isNumber(temp) ? stoi(temp) : 0;

            // Processar Bedrooms
            getline(ss, temp, ','); 
            item.bedrooms = isNumber(temp) ? stoi(temp) : 0;

            // Processar Beds
            getline(ss, temp, ','); 
            item.beds = isNumber(temp) ? stoi(temp) : 0;

            // Processar Price
            getline(ss, temp, ','); 
            item.price = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Minimum Nights
            getline(ss, temp, ','); 
            item.minimum_nights = isNumber(temp) ? stoi(temp) : 0;

            // Processar Availability 365
            getline(ss, temp, ','); 
            item.availability_365 = isNumber(temp) ? stoi(temp) : 0;

            // Processar Number of Reviews
            getline(ss, temp, ','); 
            item.number_of_reviews = isNumber(temp) ? stoi(temp) : 0;

            // Processar Review Scores Rating
            getline(ss, temp, ','); 
            item.review_scores_rating = isFloat(temp) ? stof(temp) : 0.0;

            // Processar License
            getline(ss, item.license, ',');
            item.license = item.license.empty() ? "unknown" : item.license; 

            // Processar Instant Bookable
            getline(ss, temp, ','); 
            item.instant_bookable = (temp == "t" || temp == "f") ? temp[0] : 'f';

            // Adicionar ao array dinâmico
            if (tamanhoAtual == capacidade) 
            {
                // Redimensionar array dinâmico
                capacidade *= 2;
                acomodacoes* novoArray = new acomodacoes[capacidade];
                for (int i = 0; i < tamanhoAtual; i++) 
                {
                    novoArray[i] = registros[i];
                }
                
                registros = novoArray;
            }

            registros[tamanhoAtual++] = item;  // Armazenar item

        } 
        catch (const exception &e) 
        {
            cerr << "Erro na linha " << linhaAtual << ": " << e.what() << endl;
            linhasProblematicas++;
        }
    }
    arquivoInicial.close();
    return 0; 
}

// Comparador para ordenar por ID
bool compararPorId(const acomodacoes& a, const acomodacoes& b) 
{
    return a.id < b.id;
}

// Comparador para ordenar por Name
bool compararPorName(const acomodacoes& a, const acomodacoes& b) 
{
    return a.name < b.name;
}

// Comparador para ordenar por Price
bool compararPorPriceCrescente(const acomodacoes& a, const acomodacoes& b) 
{
    return a.price < b.price;
}
bool compararPorPriceDecrescente(const acomodacoes& a, const acomodacoes& b) 
{
    return a.price > b.price;
}
// Comparador para ordenar por Number of Reviews
bool compararPorReviews(const acomodacoes& a, const acomodacoes& b) 
{
    return a.review_scores_rating > b.review_scores_rating;
}

// Tipo para o critério de comparação (função ou lambda)
using Comparador = bool(*)(const acomodacoes&, const acomodacoes&);

// Função de particionamento genérica
int partition(acomodacoes* registros, int low, int high, Comparador comparador) 
{
    acomodacoes pivot = registros[high]; // Escolhe o último elemento como pivô
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) 
    {
        if (comparador(registros[j], pivot)) 
        { // Usa o critério de comparação
            i++;
            swap(registros[i], registros[j]);
        }
    }
    swap(registros[i + 1], registros[high]);
    return (i + 1);
}

// Função Quick Sort genérica
void quickSort(acomodacoes* registros, int low, int high, Comparador comparador) 
{
    if (low < high) 
    {
        int pi = partition(registros, low, high, comparador);

        quickSort(registros, low, pi - 1, comparador);
        quickSort(registros, pi + 1, high, comparador);
    }
}

void ordenacaoBase(acomodacoes* registros, int tamanhoAtual) 
{
    quickSort(registros, 0, tamanhoAtual - 1, compararPorId);
}

void listarPorCampo(acomodacoes* registros, int tamanhoAtual, const string& campo, const string& valor) 
{
    for (int i = 0; i < tamanhoAtual; i++) 
    {
        if (campo == "name" && registros[i].name == valor) 
        {
            cout << "ID: " << registros[i].id << ", Nome: " << registros[i].name << endl;
        }
        else if (campo == "host_name" && registros[i].host_name == valor)
        {
            cout << "ID: " << registros[i].id << ", Host Name: " << registros[i].host_name << endl;
        }
    }
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


void menuImprime(acomodacoes* registros, int tamanhoAtual) {
    int tamanhoInicial = 0, tamanhoFinal = 35;

    // Criar uma cópia inicial do array de registros
    acomodacoes* registrosFiltrados = new acomodacoes[tamanhoAtual];
    copy(registros, registros + tamanhoAtual, registrosFiltrados); // Copiar os dados originais
    int tamanhoFiltrado = tamanhoAtual;

    bool running = true;

    while (running) {
        int selecionado = imprimeValores(registrosFiltrados, tamanhoFiltrado, tamanhoInicial, tamanhoFinal);
       
       
        if (selecionado == -20) {
            clearConsole();
            curs_set(0);

            int seleciona = printMenu2(); // Exibe o menu de filtros; 

            if (seleciona == 1) 
            {
                // Ordenação por preço
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceCrescente);
            } 
            else if (seleciona == 2) 
            {
                // Ordenação por avaliações
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceDecrescente);
            } 
            else if (seleciona == 3) 
            {
                // Ordenação por avaliações
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorReviews);
            } 
            else if (seleciona == 4) 
            {
                // Filtragem por faixa de preço
                float precoMin, precoMax;
                cout << "Digite o preço mínimo: ";
                cin >> precoMin;
                cout << "Digite o preço máximo: ";
                cin >> precoMax;

                acomodacoes* filtrados = new acomodacoes[tamanhoFiltrado];
                int tamanhoFiltradoAtual = 0;

                for (int i = 0; i < tamanhoFiltrado; i++) 
                {
                    if (registrosFiltrados[i].price >= precoMin && registrosFiltrados[i].price <= precoMax) {
                        filtrados[tamanhoFiltradoAtual++] = registrosFiltrados[i];
                    }
                }

                if (tamanhoFiltradoAtual > 0) 
                {
                    // Atualizar os registros filtrados
                    delete[] registrosFiltrados; // Liberar a memória antiga
                    registrosFiltrados = filtrados;
                    tamanhoFiltrado = tamanhoFiltradoAtual;
                    tamanhoInicial = 0;
                    tamanhoFinal = 35;
                } 
                else 
                {
                    delete[] filtrados; // Liberar memória se não houver registros filtrados
                    cout << "Nenhuma acomodação encontrada nessa faixa de preço." << endl;
                    sleep(2);
                }
                quickSort(registrosFiltrados, 0, tamanhoFiltrado - 1, compararPorPriceCrescente);
            } 
            else if (seleciona == 5) 
            {
                // Restaurar a cópia original dos registros
                delete[] registrosFiltrados; // Liberar a memória antiga
                registrosFiltrados = new acomodacoes[tamanhoAtual];
                copy(registros, registros + tamanhoAtual, registrosFiltrados); // Recriar a cópia
                tamanhoFiltrado = tamanhoAtual;
                tamanhoInicial = 0;
                tamanhoFinal = 35;
            } 
            else 
            {
                cout << "Seleção inválida." << endl;
                sleep(2);
            }
        } 
        else if (selecionado == -10) 
        { // Voltar ao menu principal            
            running = false;
        }
        else if (selecionado >= 0) 
        {
            curs_set(0);
            mostrarDetalhesAcomodacao(registrosFiltrados, tamanhoFiltrado, selecionado, tamanhoInicial, tamanhoFinal);
        }
    }

    // Liberar a memória dos registros filtrados antes de sair
    delete[] registrosFiltrados;
}