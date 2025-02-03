#include <string>
using namespace std;  

struct acomodacoes 
{
    long long id = 0;
    char name[100] = "unknown";  // Tamanho máximo para o nome
    long long host_id = 0;
    char host_name[100] = "unknown";  // Host name com tamanho fixo
    int host_since = 0;
    char host_response_time[50] = "unknown";  // Resposta do host com limite de tamanho
    float host_response_rate = 0.0;
    char host_is_superhost = 'f';
    char neighbourhood_cleansed[100] = "unknown";  // Bairro com tamanho fixo
    char neighbourhood_group_cleansed[100] = "unknown";  // Grupo de bairro
    float latitude = 0.0;
    float longitude = 0.0;
    char property_type[100] = "unknown";  // Tipo de propriedade
    char room_type[100] = "unknown";  // Tipo de quarto
    int accommodates = 0;
    int bathrooms = 0;
    int bedrooms = 0;
    int beds = 0;
    float price = 0.0;
    int minimum_nights = 0;
    int availability_365 = 0;
    int number_of_reviews = 0;
    float review_scores_rating = 0.0;
    char license[50] = "unknown";  // Licença com tamanho fixo
    char instant_bookable = 'f';
};


using Comparador = bool(*)(const acomodacoes&, const acomodacoes&);

void printBanner();

int printMenu1();

int printMenu2();

int printSubMenu1();

int leituraCSV(string nomeArquivo, acomodacoes*& registros, int& tamanhoAtual);

void listarPorCampo(acomodacoes* registros, int tamanhoAtual, const string& campo, const string& valor);

void ordenacaoBase(acomodacoes* registros, int tamanhoAtual);

void clearConsole();

void menuImprime(acomodacoes* registros, int tamanhoAtual);

int interactiveMenu(const string options[], int optionCount, const string& header);

void mostrarDetalhesAcomodacao(acomodacoes* registros, int tamanhoAtual, int idSelecionado, int& tamanhoInicial, int& tamanhoFinal);

int excluirRegistro(acomodacoes* registros, int& tamanhoAtual, const string& nomeArquivoNovo);

int adicionarRegistro(acomodacoes* registros, int& tamanhoAtual, int capacidadeMax, const string& nomeArquivo);

int alteraRegistro(acomodacoes* registros, int tamanhoAtual, const string& nomeArquivo);

bool compararPorId(const acomodacoes& a, const acomodacoes& b);

void quickSort(acomodacoes* registros, int low, int high, Comparador comparador);

bool compararPorPriceCrescente(const acomodacoes& a, const acomodacoes& b);

bool compararPorPriceDecrescente(const acomodacoes& a, const acomodacoes& b);

bool compararPorReviews(const acomodacoes& a, const acomodacoes& b);

int partition(acomodacoes* registros, int low, int high, Comparador comparador);

void carregarBinario(acomodacoes*& registros, int& tamanhoAtual, int& capacidade, const string& nomeArquivo);

void salvarBinario(acomodacoes* registros, int tamanhoAtual, const string& nomeArquivo);

int imprimeValores(acomodacoes* registros, int tamanhoAtual, int tamanhoInicial, int tamanhoFinal);