#include <iostream>
using namespace std;

void printMenu1() {
    const string menu1 = R"(
  ***************************************
  *       __  __                        *
  *      |  \/  |___ _ _ _  _           *
  *      | |\/| / -_) ' \ || |          *
  *      |_|  |_\___|_||_\_,_|          *
  *                                     *
  ***************************************

  Escolha uma das opções abaixo:

  [1] Busca de Registros
  [2] Alteração e Remoção
  [3] Cadastro de Novos Registros
  [4] Sair

  ***************************************
    )";

    cout << menu1 << endl;
}
