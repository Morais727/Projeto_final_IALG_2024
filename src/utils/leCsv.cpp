/**
 * @file leCsv.cpp
 * @brief Implementação de funções para leitura, processamento e ordenação de dados de acomodações.
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
#include <unistd.h>  // Para usar usleep
#include <cstdlib>
#include <ncurses.h> // Visualizações sofisticadas
#include <cstring>

using namespace std;

/**
 * @typedef Comparador
 * @brief Tipo para o critério de comparação (função ou lambda).
 */
using Comparador = bool(*)(const acomodacoes&, const acomodacoes&);

/**
 * @brief Remove emojis de uma string.
 * @param input A string de entrada que pode conter emojis.
 * @return A string sem emojis.
 */
string removeEmojis(const string &input) 
{
    regex emojiRegex("[\\xF0-\\xF7][\\x80-\\xBF]{2,3}");
    return regex_replace(input, emojiRegex, "");
}

/**
 * @brief Verifica se uma string representa um número.
 * @param str A string a ser verificada.
 * @return true se a string for um número, false caso contrário.
 */
bool isNumber(const string &str) 
{
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

/**
 * @brief Verifica se uma string representa um número de ponto flutuante.
 * @param str A string a ser verificada.
 * @return true se a string for um número de ponto flutuante, false caso contrário.
 */
bool isFloat(const string &str) 
{
    istringstream iss(str);
    float temp;
    return (iss >> temp) && iss.eof();
}

// Contar o número total de linhas no arquivo
int contarLinhasArquivo(string nomeArquivo) 
{
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) 
    {
        cerr << "Erro ao abrir o arquivo para contagem de linhas." << endl;
        return 0;
    }

    int totalLinhas = 0;
    string linha;
    while (getline(arquivo, linha)) 
    {
        totalLinhas++;
    }

    arquivo.close();
    return totalLinhas;
}


/**
 * @brief Lê um arquivo CSV e armazena os registros em um array dinâmico.
 * @param nomeArquivo O nome do arquivo CSV a ser lido.
 * @param registros Um ponteiro para o array dinâmico de acomodações.
 * @param tamanhoAtual O tamanho atual do array dinâmico.
 * @return 0 em caso de sucesso, 1 em caso de erro.
 */
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

    // Contar o total de linhas no arquivo para calcular o progresso
    int totalLinhas = contarLinhasArquivo(nomeArquivo); // Obtém o total de linhas

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
            string tempName;
            getline(ss, tempName, ',');
            strncpy(item.name, tempName.c_str(), sizeof(item.name) - 1);  // Copia para o char[100]
            
            // Processar Host ID
            getline(ss, temp, ',');
            item.host_id = isNumber(temp) ? stoll(temp) : 0;

            // Processar Nome do Host
            string tempHost_name;
            getline(ss, tempHost_name, ',');
            strncpy(item.host_name, tempHost_name.c_str(), sizeof(item.host_name) - 1);

            // Processar Host Since
            getline(ss, temp, ',');
            item.host_since = isNumber(temp) ? stoi(temp) : 0;

            // Processar Host Response Time
            string tempHost_response_time;
            getline(ss, tempHost_response_time, ',');
            strncpy(item.host_response_time, tempHost_response_time.c_str(), sizeof(item.host_response_time) - 1);

            // Processar Host Response Rate
            getline(ss, temp, ',');
            item.host_response_rate = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Superhost
            getline(ss, temp, ',');
            item.host_is_superhost = (temp == "t" || temp == "f") ? temp[0] : 'f';

            // Processar Neighborhood Cleansed
            string tempNeighbourhood_cleansed;
            getline(ss, tempNeighbourhood_cleansed, ',');
            strncpy(item.neighbourhood_cleansed, tempNeighbourhood_cleansed.c_str(), sizeof(item.neighbourhood_cleansed) - 1);

            // Processar Neighborhood Group Cleansed
            string tempNeighbourhood_group_cleansed;
            getline(ss, tempNeighbourhood_group_cleansed, ',');
            strncpy(item.neighbourhood_group_cleansed, tempNeighbourhood_group_cleansed.c_str(), sizeof(item.neighbourhood_group_cleansed) - 1);

            // Processar Latitude
            getline(ss, temp, ',');
            item.latitude = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Longitude
            getline(ss, temp, ',');
            item.longitude = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Property Type
            string tempProperty_type;
            getline(ss, tempProperty_type, ',');
            strncpy(item.property_type, tempProperty_type.c_str(), sizeof(item.property_type) - 1);

            // Processar Room Type
            string tempRoom_type;
            getline(ss, tempRoom_type, ',');
            strncpy(item.room_type, tempRoom_type.c_str(), sizeof(item.room_type) - 1);

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
            string tempLicense;
            getline(ss, tempLicense, ',');  // Lê o valor da licença
            if (tempLicense.empty()) 
            {
                strncpy(item.license, "unknown", sizeof(item.license) - 1);
            } 
            else 
            {
                strncpy(item.license, tempLicense.c_str(), sizeof(item.license) - 1);
            }
            item.license[sizeof(item.license) - 1] = '\0'; // Garante terminação correta

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
        
        // Atualizar a barra de progresso a cada linha processada
        exibirBarraCarregamento(linhaAtual, totalLinhas);
        
    }
    arquivoInicial.close();

    return 0; 
}

/**
 * @brief Comparador para ordenar por ID.
 * @param a Primeira acomodação a ser comparada.
 * @param b Segunda acomodação a ser comparada.
 * @return true se o ID de `a` for menor que o de `b`, false caso contrário.
 */
bool compararPorId(const acomodacoes& a, const acomodacoes& b) 
{
    return a.id < b.id;
}

/**
 * @brief Comparador para ordenar por Name.
 * @param a Primeira acomodação a ser comparada.
 * @param b Segunda acomodação a ser comparada.
 * @return true se o nome de `a` for menor que o de `b`, false caso contrário.
 */
bool compararPorName(const acomodacoes& a, const acomodacoes& b) 
{
    return string(a.name) < string(b.name);
}

/**
 * @brief Comparador para ordenar por Price (crescente).
 * @param a Primeira acomodação a ser comparada.
 * @param b Segunda acomodação a ser comparada.
 * @return true se o preço de `a` for menor que o de `b`, false caso contrário.
 */
bool compararPorPriceCrescente(const acomodacoes& a, const acomodacoes& b) 
{
    return a.price < b.price;
}

/**
 * @brief Comparador para ordenar por Price (decrescente).
 * @param a Primeira acomodação a ser comparada.
 * @param b Segunda acomodação a ser comparada.
 * @return true se o preço de `a` for maior que o de `b`, false caso contrário.
 */
bool compararPorPriceDecrescente(const acomodacoes& a, const acomodacoes& b) 
{
    return a.price > b.price;
}

/**
 * @brief Comparador para ordenar por Number of Reviews.
 * @param a Primeira acomodação a ser comparada.
 * @param b Segunda acomodação a ser comparada.
 * @return true se a pontuação de avaliação de `a` for maior que a de `b`, false caso contrário.
 */
bool compararPorReviews(const acomodacoes& a, const acomodacoes& b) 
{
    return a.review_scores_rating > b.review_scores_rating;
}

/**
 * @brief Função de particionamento genérica para o Quick Sort.
 * @param registros O array de acomodações a ser particionado.
 * @param low O índice inicial do subarray.
 * @param high O índice final do subarray.
 * @param comparador O critério de comparação.
 * @return O índice do pivô após o particionamento.
 */
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

/**
 * @brief Função Quick Sort genérica.
 * @param registros O array de acomodações a ser ordenado.
 * @param low O índice inicial do subarray.
 * @param high O índice final do subarray.
 * @param comparador O critério de comparação.
 */
void quickSort(acomodacoes* registros, int low, int high, Comparador comparador) 
{
    if (low < high) 
    {
        int pi = partition(registros, low, high, comparador);

        quickSort(registros, low, pi - 1, comparador);
        quickSort(registros, pi + 1, high, comparador);
    }
}

/**
 * @brief Ordena o array de acomodações por ID.
 * @param registros O array de acomodações a ser ordenado.
 * @param tamanhoAtual O tamanho atual do array.
 */
void ordenacaoBase(acomodacoes* registros, int tamanhoAtual) 
{
    quickSort(registros, 0, tamanhoAtual - 1, compararPorId);
}

/**
 * @brief Lista acomodações com base em um campo e valor específicos.
 * @param registros O array de acomodações.
 * @param tamanhoAtual O tamanho atual do array.
 * @param campo O campo a ser filtrado.
 * @param valor O valor a ser comparado.
 */
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