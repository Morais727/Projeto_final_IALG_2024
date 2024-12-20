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

using namespace std;

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
                delete[] registros;  // Liberar memória antiga
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
bool compararPorPrice(const acomodacoes& a, const acomodacoes& b) 
{
    return a.price < b.price;
}

// Comparador para ordenar por Number of Reviews
bool compararPorReviews(const acomodacoes& a, const acomodacoes& b) 
{
    return a.number_of_reviews < b.number_of_reviews;
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

void imprimeValores(acomodacoes* registros, int tamanhoAtual, int tamanhoInicial, int tamanhoFinal)
{
    // Cabeçalho (opcional)
    cout << left << setw(10) << "Preço" << setw(50) << "Nome" << endl;
    cout << string(60, '-') << endl; // Linha de separação

    // Imprimir os valores
    for (int i = tamanhoInicial; i < tamanhoFinal; i++)
    {       
        // Formatação do preço com 2 casas decimais
        cout << left << setw(10) << fixed << setprecision(2) << registros[i].price
             << setw(50) << registros[i].name << endl;
    }

}

void menuImprime(acomodacoes* registros, int tamanhoAtual)
{
    clearConsole();

    int tamanhoInicial = 0, tamanhoFinal = 40;

    char continua;
    bool imprime = true;

    imprimeValores(registros, tamanhoAtual, tamanhoInicial, tamanhoFinal);

     while (imprime == true)
    {
        tamanhoInicial += 40;
        tamanhoFinal += 40;

        // Move o cursor para a última linha
        system("tput cup 50 0");
        cout << endl << "Próxima página? (S/N)                  Filtrar? (F)" << endl;

        cin >> continua;
        continua = tolower(continua);

        clearConsole();

        if (continua == 's')
        {
            imprime = true;
            imprimeValores(registros, tamanhoAtual, tamanhoInicial, tamanhoFinal);
        }
        else if (continua == 'n')
        {
            imprime = false;            

            cout << "Voltando ao menu anterior. " << endl;

            sleep(2);
            clearConsole();

            printMenu1();
        }
        else if (continua == 'f')
        {
            printMenu2();
            
            int seleciona, valor;

            cin >> seleciona;

            clearConsole();

            cout << "Digite o valor a ser filtrado: " << endl;
            cin >> valor;

            if (seleciona == 1)
            {
                tamanhoInicial = 0;
                tamanhoFinal = 40;

                quickSort(registros, 0, tamanhoAtual - 1, compararPorPrice);  
                imprimeValores(registros, tamanhoAtual, tamanhoInicial, tamanhoFinal);          
            }
            else if (seleciona == 2)
            {
                tamanhoInicial = 0;
                tamanhoFinal = 40;

                quickSort(registros, 0, tamanhoAtual - 1, compararPorReviews);  
                imprimeValores(registros, tamanhoAtual, tamanhoInicial, tamanhoFinal);
            }
            else
            {
                clearConsole();

                cout << "Selecione uma opção válida! " << endl;

                sleep(2);
                clearConsole();

                tamanhoInicial -= 40;
                tamanhoFinal -= 40;
                imprimeValores(registros, tamanhoAtual, tamanhoInicial, tamanhoFinal);
            }
        }
        else
        {
            clearConsole();

            cout << "Selecione uma opção válida! " << endl;

            sleep(2);
            clearConsole();

            tamanhoInicial -= 40;
            tamanhoFinal -= 40;
            imprimeValores(registros, tamanhoAtual, tamanhoInicial, tamanhoFinal);
        }
    }


    
}