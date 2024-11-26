#include <string>
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


void printBanner();

void printMenu1();

int leituraCSV(string nomeArquivo, acomodacoes*& registros, int& tamanhoAtual);

