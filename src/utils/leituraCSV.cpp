#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <exception>
#include "utils.h"

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

    while (getline(arquivoInicial, linha)) 
    {
        linhaAtual++;
        linha = removeEmojis(linha);  // Remover emojis ou caracteres indesejados
        istringstream ss(linha);
        acomodacoes item;
        string temp;

        try 
        {
            // Processar os dados do CSV conforme já feito

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

void ordenacaoBase(acomodacoes* registros, int tamanhoAtual)
{
    for (int i = 0; i < tamanhoAtual - 1; i++) 
    {
        for (int j = i + 1; j < tamanhoAtual; j++) 
        {
            if (registros[i].id > registros[j].id) 
            {
                acomodacoes temp = registros[i];
                registros[i] = registros[j];
                registros[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++) 
    {
        cout << registros[i].id << endl;
    }
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