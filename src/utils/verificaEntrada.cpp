#include <iostream>
#include "utils.h"

bool isNumber(const char* input) {
    if (*input == '\0') return false; // Verifica se a string está vazia

    int i = 0;
    if (input[0] == '+' || input[0] == '-') i++; // Permite sinal no início

    while (input[i] != '\0') {
        if (input[i] < '0' || input[i] > '9') {
            return false; // Se não for dígito, não é um número
        }
        i++;
    }

    return true;
}
