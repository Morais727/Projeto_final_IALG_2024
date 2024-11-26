#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// Função para tentar converter para número (int)
bool isNumeric(const string &str) {
    try {
        stoi(str); // Tenta converter a string para número inteiro
        return true; // Retorna verdadeiro se a conversão for bem-sucedida
    } catch (...) {
        return false; // Retorna falso se ocorrer uma exceção
    }
}

void processarCSV(const string &inputFile, const string &outputFile) {
    ifstream arquivoEntrada(inputFile);
    ofstream arquivoSaida(outputFile);

    if (!arquivoEntrada.is_open()) {
        cerr << "Erro ao abrir o arquivo de entrada." << endl;
        return;
    }

    if (!arquivoSaida.is_open()) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        return;
    }

    string linha;
    bool isFirstLine = true; // Identifica o cabeçalho

    while (getline(arquivoEntrada, linha)) {
        if (isFirstLine) {
            // Escreve o cabeçalho diretamente no arquivo de saída
            arquivoSaida << linha << endl;
            isFirstLine = false;
            continue;
        }

        istringstream ss(linha);
        vector<string> colunas;
        string temp;

        // Separar as colunas usando a vírgula como delimitador
        while (getline(ss, temp, ',')) {
            colunas.push_back(temp);
        }

        if (colunas.size() >= 3) { // Verifica se a linha tem pelo menos 3 colunas
            string host_id = colunas[2]; // Terceira coluna

            if (!isNumeric(host_id)) {
                // Caso host_id não seja numérico, concatena a terceira coluna com a segunda
                colunas[1] += " " + colunas[2]; // Concatena a segunda e a terceira coluna
                colunas.erase(colunas.begin() + 2); // Remove a terceira coluna
            }
        }

        // Escrever a linha modificada no arquivo de saída
        for (size_t i = 0; i < colunas.size(); ++i) {
            arquivoSaida << colunas[i];
            if (i < colunas.size() - 1) {
                arquivoSaida << ","; // Adiciona a vírgula entre as colunas
            }
        }
        arquivoSaida << endl; // Nova linha após cada linha do CSV
    }

    arquivoEntrada.close();
    arquivoSaida.close();
}

int main() {
    string inputFile = "saidaa.csv";   // Arquivo de entrada
    string outputFile = "saidaaa.csv";   // Arquivo de saída

    processarCSV(inputFile, outputFile);

    cout << "Processamento concluído. Verifique o arquivo " << outputFile << endl;

    return 0;
}
