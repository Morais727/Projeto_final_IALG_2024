#include <iostream>
#include <ncurses.h>

using namespace std;

void printBanner() 
{
    
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

    cout << banner << endl;
    curs_set(0); // Esconde o cursor
}