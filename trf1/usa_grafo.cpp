/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#include "Grafo.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

void menu() {
  int v = 0, o = 0;
  cin >> v >> o;

  if ((v > 0) && (o >0)) {
    Grafo grafo(v);

    for (int i = 0; i < o; i++) {
      char op = ' ';
      int x = 0, y = 0;

      cin >> op;
      switch (op) {
      case 'I':
        cin >> x >> y;
        grafo.insere_aresta(Aresta(x,y));
        break;
      case 'R':
        cin >> x >> y;
        grafo.remove_aresta(Aresta(x,y));
        break;
      case 'E':
        grafo.num_arestas();
        break;
      case 'X':
        grafo.grau_maximo();
        break;
      case 'N':
        grafo.grau_minimo();
        break;
      case 'P':
        grafo.imprime();
        break;
      default:
        break;
      }
    }
  }
}

int main() {
  menu();

  return 0;
}
