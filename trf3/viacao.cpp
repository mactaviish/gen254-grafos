/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#include "Digrafo.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

int main() {
  int c = 0, t = 0;
  cin >> c >> t;
  
  if ((c > 0) && (t >= 0)) {
    Digrafo digrafo(c);

    for (int i = 0; i < t; i++) {
      int x = 0, y = 0, z = 0;
      cin >> x >> y >> z;
      digrafo.insere_trecho(x, Aresta(y, z));
    }

    int r = 0, x = 0, m = 0;
    cin >> r;
    if (r >= 0) {
      for (int i = 0; i < r; i++) {
        cin >> x >> m;
        digrafo.reavaliacao(x, m);
      }
    }
  }

  return 0;
}
