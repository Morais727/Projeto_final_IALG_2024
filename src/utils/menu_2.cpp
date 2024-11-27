#include <iostream>
using namespace std;

void printMenu2() {
    const string menu2 = R"(
  ****************************************
  *      _____ _ _ _                     *
  *    |  ___(_) | |_ _ __ __ _ _ __     *
  *    | |_  | | | __| '__/ _` | '__|    *
  *    |  _| | | | |_| | | (_| | |       *  
  *    |_|   |_|_|\__|_|  \__,_|_|       *
  *                                      *
  ****************************************

  Escolha uma das opções abaixo:

  [1] Filtrar por preço
  [2] Filtrar por reviews
  
  ***************************************
  )";

    cout << menu2 << endl;
}
