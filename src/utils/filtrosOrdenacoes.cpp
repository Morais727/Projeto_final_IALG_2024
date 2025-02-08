#include <iostream>
#include "utils.h"
#include <map>
#include <unistd.h>  // Para usar usleep

using namespace std;

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

void listarPorCampo(acomodacoes* registrosFiltrados, int& tamanhoAtual, const string& campo, const string& valor) {
    // Criar um array temporário do mesmo tamanho de registros
    acomodacoes* registrosFiltradosCampos = new acomodacoes[tamanhoAtual];
    int tamanhoFiltradoAtual = 0;

    // Criação do mapa com chave do tipo int e valor do tipo string
    map<int, string> dicionario;

    // Inserindo elementos no mapa (campo - chave)
    dicionario[1] = "name";
    dicionario[2] = "host_name";
    dicionario[3] = "bedrooms";
    dicionario[4] = "bathrooms";

    // Converte a string de campo para número 
    int chave = stoi(campo);
    string campoFiltrado;

    // Verifica se a chave está no mapa
    if (dicionario.find(chave) != dicionario.end()) {
        campoFiltrado = dicionario[chave];  // Obtém o campo correspondente à chave
    } else {
        cout << "Chave inválida!" << endl;
        delete[] registrosFiltradosCampos; // Libera memória alocada para registrosFiltradosCampos
        return;
    }

    // Aplica o filtro de acordo com o campo e valor
    for (int i = 0; i < tamanhoAtual; i++) {
        if (campoFiltrado == "name" && registrosFiltrados[i].name == valor) {
            registrosFiltradosCampos[tamanhoFiltradoAtual++] = registrosFiltrados[i];
        }
        else if (campoFiltrado == "host_name" && registrosFiltrados[i].host_name == valor) {
            registrosFiltradosCampos[tamanhoFiltradoAtual++] = registrosFiltrados[i];
        }
        else if (campoFiltrado == "bedrooms") {
            int valorInt = stoi(valor);  // Converte o valor para inteiro
            if (registrosFiltrados[i].bedrooms == valorInt) {
                registrosFiltradosCampos[tamanhoFiltradoAtual++] = registrosFiltrados[i];
            }
        }
        else if (campoFiltrado == "bathrooms") {
            int valorInt = stoi(valor);  // Converte o valor para inteiro
            if (registrosFiltrados[i].bathrooms == valorInt) {
                registrosFiltradosCampos[tamanhoFiltradoAtual++] = registrosFiltrados[i];
            }
        }
    }
    if (tamanhoFiltradoAtual > 0) 
    {
        // Criar um novo array com o tamanho exato
        acomodacoes* novoArray = new acomodacoes[tamanhoFiltradoAtual];
        for (int i = 0; i < tamanhoFiltradoAtual; i++) 
        {
            novoArray[i] = registrosFiltradosCampos[i];
        }

        delete[] registrosFiltrados;

        registrosFiltrados = novoArray;
        tamanhoAtual = tamanhoFiltradoAtual;

        delete[] novoArray;
    } 
    else 
    {
        // Nenhum registro encontrado no filtro
        cout << "Nenhum registro encontrado para o campo " << campo << " com o valor " << valor << endl;
        sleep(2);
    }
}
