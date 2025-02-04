/**
 * @file banner.cpp
 * @author Marcos Morais
 * @date 03/02/2025
 * @brief Exibe um banner ASCII e inicializa a interface do sistema.
 * 
 * O banner contém um título estilizado e a localização do sistema. Após exibir o banner,
 * o cursor é ocultado e o programa aguarda 2 segundos antes de continuar.
 */

#include <iostream>
#include <ncurses.h>
#include <unistd.h>  // Para a função sleep()

using namespace std;

/**
 * @brief Exibe um banner ASCII e inicializa a interface do sistema.
 */
void printBanner() 
{
    // Banner ASCII do sistema
    const string banner = R"(
                                                                                                    

    █████   ██████  ██████  ███    ███  ██████  ██████   █████   ██████  ██████  ███████ ███████ 
    ██   ██ ██      ██    ██ ████  ████ ██    ██ ██   ██ ██   ██ ██      ██    ██ ██      ██      
    ███████ ██      ██    ██ ██ ████ ██ ██    ██ ██   ██ ███████ ██      ██    ██ █████   ███████ 
    ██   ██ ██      ██    ██ ██  ██  ██ ██    ██ ██   ██ ██   ██ ██      ██    ██ ██           ██ 
    ██   ██  ██████  ██████  ██      ██  ██████  ██████  ██   ██  ██████  ██████  ███████ ███████                                                                                                                                                                                             
                                            Los Angeles - CA


    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Inicializando Sistema de Gerenciamento de Registro de Acomodações                                                                                
    )";

    // Exibe o banner no console
    cout << banner << endl;

    // Esconde o cursor para uma melhor experiência visual
    curs_set(0);

    // Pausa por 2 segundos antes de prosseguir
    sleep(2);
}
