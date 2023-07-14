/*
 * Tarefa 02 - Testes em Circuitos Integrados
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
    bool existe_aresta(int x, int y);
    bool caminho(int v, int w, std::list<int> marcado);
    bool busca(int v);
    bool existe_ciclo(int v);
    std::vector<std::list<int>> lista_adj_;
public:
    Grafo(int num_vertices);
    void insere_aresta(Aresta e);
    bool eh_caminho();
    bool existe_caminho();
    bool eh_conexo();
    bool eh_aciclico();
};

#endif /* GRAFO_H */
