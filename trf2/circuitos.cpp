/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#include "Grafo.h"
#include "Aresta.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

void print_exception(const exception &e, int level = 0) {
  cerr << "exception: " << string(level, ' ') << e.what() << "\n";
  try {
    rethrow_if_nested(e);
  } catch(const std::exception& nested_exception) {
    print_exception(nested_exception, (level + 2));
  }
}

void printBool(bool validacao) {
  if (validacao) {
    cout << "SIM" << endl;
  } else {
    cout << "NAO" << endl;
  }
}

void menu() {
  int v = 0, o = 0, e = 0;
  cin >> v >> e;

  if ((v > 0) && (e >= 0)) {
    Grafo grafo(v);

    for (int i = 0; i < e; i++) {
      int x = 0, y = 0, n = 0;
      cin >> x >> y;
      grafo.insere_aresta(Aresta(x,y));
    }

    cin >> o;
    if (o >= 0) {
      for (int i = 0; i < o; i++) {
        char op = ' ';
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> op;

        switch (toupper(op)) {
          case 'S':
            printBool(grafo.eh_caminho());
            break;
          case 'C':
            printBool(grafo.existe_caminho());
            break;
          case 'X':
            printBool(grafo.eh_conexo());
            break;
          case 'A':
            printBool(grafo.eh_aciclico());
            break;
          default:
            break;
        }
      }
    }
  }
}

int main() {
  try {
    menu();
  }
  catch (const exception &e) {
    print_exception(e);
  }

  return 0;
}
