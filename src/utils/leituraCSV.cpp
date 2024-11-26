#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include <exception>

using namespace std;

struct acomodacoes {
    long long id = 0;
    string name = "unknown";
    long long host_id = 0;
    string host_name = "unknown";
    int host_since = 0;
    string host_response_time = "unknown";
    float host_response_rate = 0.0;
    char host_is_superhost = 'f';
    string neighbourhood_cleansed = "unknown";
    string neighbourhood_group_cleansed = "unknown";
    float latitude = 0.0;
    float longitude = 0.0;
    string property_type = "unknown";
    string room_type = "unknown";
    int accommodates = 0;
    int bathrooms = 0;
    int bedrooms = 0;
    int beds = 0;
    float price = 0.0;
    int minimum_nights = 0;
    int availability_365 = 0;
    int number_of_reviews = 0;
    float review_scores_rating = 0.0;
    string license = "unknown";
    char instant_bookable = 'f';
};

// void exibirDados(const vector<acomodacoes>& registros) {
//     cout << "\n--- Dados Processados ---\n";
//     for (const auto& item : registros) {
//         cout << "ID: " << item.id
//              << ", Nome: " << item.name
//              << ", Host ID: " << item.host_id
//              << ", Host Name: " << item.host_name
//              << ", host_since: " << item.host_since
//              << ", host_response_time: " << item.host_response_time
//              << ", host_response_rate: " << item.host_response_rate
//              << ", host_is_superhost: " << item.host_is_superhost
//              << ", neighbourhood_cleansed: " << item.neighbourhood_cleansed
//              << ", neighbourhood_group_cleansed: " << item.neighbourhood_group_cleansed
//              << ", Latitude: " << item.latitude
//              << ", Longitude: " << item.longitude
//              << ", property_type: " << item.property_type
//              << ", room_type: " << item.room_type
//              << ", accommodates: " << item.accommodates
//              << ", bathrooms: " << item.bathrooms
//              << ", bedrooms: " << item.bedrooms             
//              << ", beds: " << item.beds
//              << ", price: " << item.price
//              << ", minimum_nights: " << item.minimum_nights
//              << ", availability_365: " << item.availability_365
//              << ", number_of_reviews: " << item.number_of_reviews
//              << ", review_scores_rating: " << item.review_scores_rating
//              << ", license: " << item.license
//              << ", Reserva Instantânea: " << item.instant_bookable
//              << endl;
//     }
// }

string removeEmojis(const string &input) {
    regex emojiRegex("[\\xF0-\\xF7][\\x80-\\xBF]{2,3}");
    return regex_replace(input, emojiRegex, "");
}

bool isNumber(const string &str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

bool isFloat(const string &str) {
    istringstream iss(str);
    float temp;
    return (iss >> temp) && iss.eof();
}

int leituraCSV(string nomeArquivo) {
    ifstream arquivoInicial(nomeArquivo);

    if (!arquivoInicial.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    vector<acomodacoes> registros;
    string linha;
    int linhaAtual = 0;
    int linhasProblematicas = 0;

    while (getline(arquivoInicial, linha)) {
        linhaAtual++;
        linha = removeEmojis(linha);
        istringstream ss(linha);
        acomodacoes item;
        string temp;

        try {
            // Processar ID
            getline(ss, temp, ',');
            item.id = isNumber(temp) ? stoll(temp) : 0;

            // Processar Nome
            getline(ss, item.name, ',');

            // Processar Host ID
            getline(ss, temp, ',');
            item.host_id = isNumber(temp) ? stoll(temp) : 0;

            // Processar Nome
            getline(ss, item.host_name, ',');

            // Processar host_since
            getline(ss, temp, ',');
            item.host_since = isNumber(temp) ? stoi(temp) : 0;

            // Processar host_response_time
            getline(ss, item.host_response_time, ',');

            // Processar Host Response Rate
            getline(ss, temp, ',');
            item.host_response_rate = isFloat(temp) ? stof(temp) : 0.0;

            // Processar Superhost
            getline(ss, temp, ',');
            item.host_is_superhost = (temp == "t" || temp == "f") ? temp[0] : 'f';

            // Processar Neighbourhood Cleansed
            getline(ss, item.neighbourhood_cleansed, ',');

            // Processar Neighbourhood Group Cleansed
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

            // Bathrooms
            getline(ss, temp, ','); 
            item.bathrooms = isNumber(temp) ? stoi(temp) : 0;

            // Bedrooms
            getline(ss, temp, ','); 
            item.bedrooms = isNumber(temp) ? stoi(temp) : 0;

            // Beds
            getline(ss, temp, ','); 
            item.beds = isNumber(temp) ? stoi(temp) : 0;

            // Price
            getline(ss, temp, ','); 
            item.price = isFloat(temp) ? stof(temp) : 0.0;

            // Minimum Nights
            getline(ss, temp, ','); 
            item.minimum_nights = isNumber(temp) ? stoi(temp) : 0;

            // Availability 365
            getline(ss, temp, ','); 
            item.availability_365 = isNumber(temp) ? stoi(temp) : 0;

            // Number of Reviews
            getline(ss, temp, ','); 
            item.number_of_reviews = isNumber(temp) ? stoi(temp) : 0;

            // Review Scores Rating
            getline(ss, temp, ','); 
            item.review_scores_rating = isFloat(temp) ? stof(temp) : 0.0;

            // License
            getline(ss, item.license, ',');
            item.license = item.license.empty() ? "unknown" : item.license; // Ajustado para garantir que a licença seja corretamente capturada

            // Instant Bookable
            getline(ss, temp, ','); 
            item.instant_bookable = (temp == "t" || temp == "f") ? temp[0] : 'f';

            // Adicionar ao vetor de registros
            registros.push_back(item);

        } catch (const exception &e) {
            cerr << "Erro na linha " << linhaAtual << ": " << e.what() << endl;
            linhasProblematicas++;
        }
    }

    arquivoInicial.close();

    // Exibir resumo
    cout << "Total de linhas processadas: " << linhaAtual << endl;
    cout << "Total de linhas problemáticas: " << linhasProblematicas << endl;
    cout << "Total de registros válidos: " << registros.size() << endl;

    // Exibir os dados processados
    // exibirDados(registros);

    return 0;
}
