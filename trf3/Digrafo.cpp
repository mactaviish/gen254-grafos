/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#include "Digrafo.h"
#include <iostream>
#include <algorithm>

using namespace std;

const int max_int = numeric_limits<int>::max();

Digrafo::Digrafo(int num_cidades) {
    num_cidades_ = num_cidades;
    num_trechos_ = 0;
    lista_adj_.resize(num_cidades);
}

void Digrafo::insere_trecho(int origem, Aresta trecho) {
  if ((origem != trecho.destino) && (trecho.extensao >= 0)) {
    lista_adj_[origem].push_back(trecho);
    num_trechos_++;
  }
}

void Digrafo::dijkstra(int origem, vector<int>& pai, vector<int>& dp, priority_queue<pair<int, int>>& Q) {
  for (int w = 0; w < num_cidades_; w++) {
    dp[w] = max_int;
    pai[w] = -1;
    if (w != origem) {
      Q.push(make_pair(-dp[w], w));
    }
  }
  dp[origem] = 0;
  Q.push(make_pair(dp[origem], origem));

  while (!Q.empty()) {
    int u = Q.top().second;
    Q.pop();
    
    if (dp[u] != max_int) {
      for (const auto& trecho : lista_adj_[u]) {
        int v = trecho.destino;
        int p = trecho.extensao;

        if (dp[v] > dp[u] + p) {
          dp[v] = dp[u] + p;
          pai[v] = u;
          Q.push(make_pair(dp[v], v));
        }
      }
    }
  }
}

void Digrafo::reavaliacao(int origem, int extensao_minima) {
  vector<int> pai(num_cidades_);
  vector<int> dp(num_cidades_);
  priority_queue<pair<int, int>> Q;

  dijkstra(origem, pai, dp, Q);

  cout << endl;
  for (int i = 0; i < dp.size(); i++) {
    if (origem != i) {
      if ((dp[i] >= extensao_minima) && (dp[i] != max_int)) {
        cout << i << ": " << dp[i] << ",";
        int v = i;
        while (v != origem) {
          cout << " " << v;
          v = pai[v];
        }
        cout << " " << origem;
      } else {
        cout << i << ": economicamente inviavel partindo de " << origem;
      }
      cout << endl;
    }
  }
}

void Digrafo::imprime_trechos() {
  int i = 0;
  for (const auto& cidade : lista_adj_) {
    cout << i << ":";
    for (const auto& trecho : cidade) {
      cout << " | " << trecho.destino << "," << trecho.extensao;
    }
    cout << endl;
    i++;
  }
}
