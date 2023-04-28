/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#include "Grafo.h"
#include <iostream>
#include <algorithm>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices; 
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices);
}

void Grafo::insere_aresta(Aresta e) {
  list<int>& v1 = lista_adj_[e.v1];
  list<int>& v2 = lista_adj_[e.v2];
  if (e.v1 != e.v2) {
    if (find(v1.begin(), v1.end(), e.v2) == v1.end()) {
      v1.push_front(e.v2);
      v2.push_front(e.v1);

      num_arestas_++;
    }
  }
}

void Grafo::remove_aresta(Aresta e) {
  list<int>& v1 = lista_adj_[e.v1];
  list<int>& v2 = lista_adj_[e.v2];

  if (find(v1.begin(), v1.end(), e.v2) != v1.end()) {
    v1.remove(e.v2);
    v2.remove(e.v1);

    num_arestas_--;
  }
}

int Grafo::num_arestas() {
  cout << num_arestas_ << endl;
  return num_arestas_;
}

int Grafo::grau_maximo() {
  int maximo = 0;

  for (int i = 0; i < static_cast<int>(lista_adj_.size()); i++) {
    int grau = lista_adj_[i].size();

    if (grau > maximo) {
      maximo = grau;
    }
  }

  cout << maximo << endl;
  return maximo;
}

int Grafo::grau_minimo() {
  int minimo = lista_adj_[0].size();

  for (int i = 0; i < static_cast<int>(lista_adj_.size()); i++) {
    int grau = lista_adj_[i].size();

    if (grau < minimo) {
      minimo = grau;
    }
  }

  cout << minimo << endl;
  return minimo;
}

void Grafo::imprime() {
  for (int i = 0; i < static_cast<int>(lista_adj_.size()); i++) {
    list<int> atual = lista_adj_[i];
    cout << i << ":";
    for (auto vertice = atual.begin(); vertice != atual.end(); vertice++) {
      cout << " " << *vertice;
    }
    cout << endl;
  }
}
