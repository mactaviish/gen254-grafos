/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#ifndef DIGRAFO_H
#define DIGRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>
#include <queue>
#include <limits>

class Digrafo {
private:
    int num_cidades_;
    int num_trechos_;
    void dijkstra(int origem, std::vector<int>& pai, std::vector<int>& dp, std::priority_queue<std::pair<int, int>>& Q);
    std::vector<std::list<Aresta>> lista_adj_;
public:
    Digrafo(int num_cidades);
    void insere_trecho(int origem, Aresta trecho);
    void reavaliacao(int origem, int extensao_minima);
    void imprime_trechos();
};

#endif /* DIGRAFO_H */

/*
// ou list<pair<int,int>>

1. implementar um digrafo com listas de adjacencia;
2. colocar peso nas arestas;
3. implementar o dijkstra;
4. imprimir os caminhos.

*/
