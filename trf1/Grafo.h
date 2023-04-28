/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:  LEONARDO YURI DALLA CORTE BRANCALIONE
 * Matricula: 1721101025
 */

#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>

class Grafo {
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> lista_adj_;
public:
    Grafo(int num_vertices);
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    int num_arestas();
    int grau_maximo();
    int grau_minimo();
    void imprime();
};

#endif /* GRAFO_H */
