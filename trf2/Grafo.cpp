/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#include "Grafo.h"
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices; 
    num_arestas_ = 0;
    lista_adj_.resize(num_vertices);
}

bool Grafo::existe_aresta(int x, int y) {
  list<int> vertice = lista_adj_[x];
  return find(vertice.begin(), vertice.end(), y) != vertice.end();
}

bool Grafo::caminho(int v, int w, std::list<int> marcado) {
  if (v == w)
    return true;

  list<int> g = lista_adj_[v];
  marcado.push_back(v);
  for (int u = 0; u < num_vertices_; u++)
    if (find(g.begin(), g.end(), u) != g.end())
      if (find(marcado.begin(), marcado.end(), u) == marcado.end())
        if (caminho(u, w, marcado))
          return true;

  return false;
}

bool Grafo::busca(int v) {
  list<int> marcado;
  stack<int> pilha;
  pilha.push(v);

  while (!pilha.empty()) {
    int w = pilha.top();
    list<int> g = lista_adj_[w];
    pilha.pop();
    if (find(marcado.begin(), marcado.end(), w) == marcado.end())
      marcado.push_back(w);
    for (int u = (num_vertices_-1); u >= 0; u--) {
      if (find(g.begin(), g.end(), u) != g.end())
        if (find(marcado.begin(), marcado.end(), u) == marcado.end())
          pilha.push(u);
    }
  }

  return marcado.size() == num_vertices_;
}

bool Grafo::existe_ciclo(int v) {
  list<int> marcado;
  vector<int> pai(num_vertices_, -1);
  stack<int> pilha;

  pilha.push(v);

  while (!pilha.empty()) {
    int w = pilha.top();
    list<int> g = lista_adj_[w];
    pilha.pop();

    if (find(marcado.begin(), marcado.end(), w) == marcado.end()) {
      marcado.push_back(w);

      for (int u = num_vertices_-1; u >= 0; u--) {
        if (find(g.begin(), g.end(), u) != g.end()) {
          if (find(marcado.begin(), marcado.end(), u) == marcado.end()) {
            pilha.push(u);
            pai[u] = w;
          } else if (pai[w] != u) {
            return true;
          }
        }
      }
    }
  }

  return false;
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

bool Grafo::eh_caminho() {
  int n = 0;
  list<int> caminho;
  list<int> visitados;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int v = 0;
    cin >> v;

    if (visitados.size() > 0) {
      if (!existe_aresta(v, visitados.back())) {
        return false;
      }
      if (find(visitados.begin(), visitados.end(), v) != visitados.end()) {
        return false;
      }
    }
    visitados.push_back(v);
  }

  return true;
}

bool Grafo::existe_caminho() {
  list<int> marcado;
  int x = 0, y = 0;
  cin >> x >> y;

  return caminho(x, y, marcado);
}

bool Grafo::eh_conexo() {
  return busca(0);
}

bool Grafo::eh_aciclico() {
  return !existe_ciclo(0);
}