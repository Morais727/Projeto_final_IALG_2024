/**
 * @file reorganizarIds.cpp
 * 
 * 
 * @brief Reorganiza os IDs das acomodações no array dinâmico após modificação.
 * 
 * Após a exclusão de um registro, os IDs são renumerados para manter uma sequência correta.
 * O primeiro registro recebe ID 0, o segundo 1 e assim por diante.
 * 
 * @author Marcos Morais
 * @date 03/02/2025
 * 
 * @param registros Ponteiro para o array dinâmico de acomodações.
 * @param tamanhoAtual Número atual de registros no array.
 */

#include "utils.h"

void reorganizarIDs(acomodacoes* registros, int tamanhoAtual) {
    for (int i = 0; i < tamanhoAtual; i++) {
        registros[i].id = i;  // Atribui o índice como novo ID
    }
}
