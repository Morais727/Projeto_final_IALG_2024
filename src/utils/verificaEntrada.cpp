/**
 * @file is_number.cpp
 * @brief Implementação da função para verificar se uma string representa um número.
 *
 * Esta função verifica se uma string contém apenas dígitos numéricos,
 * retornando verdadeiro se a string for um número válido e falso caso contrário.
 *
 * @author Seu Nome
 * @date 07/02/2025
 */

#include <iostream>
#include "utils.h"

/**
 * @brief Verifica se uma string contém apenas números.
 *
 * Esta função percorre a string de entrada e verifica se todos os caracteres
 * são dígitos numéricos ('0' a '9'). Se houver qualquer caractere não numérico,
 * a função retorna falso.
 *
 * @param input Ponteiro para a string de entrada a ser verificada.
 * @return true se a string contém apenas números, false caso contrário.
 */
bool isNumber(const char* input) 
{
    if (*input == '\0') return false; // Verifica se a string está vazia

    int i = 0;

    while (input[i] != '\0') {
        if (input[i] < '0' || input[i] > '9') {
            return false; // Se não for dígito, retorna falso
        }
        i++;
    }

    return i > 0; // Retorna verdadeiro apenas se houver pelo menos um dígito
}
