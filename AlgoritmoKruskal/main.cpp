#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Arista
{
    int peso;
    char src, dest;
};

struct Grafo
{
    int V, E;
    struct Arista* arista;
};


struct Grafo* createGraph(int V, int E)
{
    struct Grafo* graph = (struct Grafo*)malloc(sizeof(struct Grafo));
    graph->V = V;
    graph->E = E;
    graph->arista = (struct Arista*)malloc(graph->E * sizeof(struct Arista));
    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xraiz = find(subsets, x);
    int yraiz = find(subsets, y);
    if (subsets[xraiz].rank < subsets[yraiz].rank)
        subsets[xraiz].parent = yraiz;
    else if (subsets[xraiz].rank > subsets[yraiz].rank)
        subsets[yraiz].parent = xraiz;
    else
    {
        subsets[yraiz].parent = xraiz;
        subsets[xraiz].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    struct Arista* a1 = (struct Arista*)a;
    struct Arista* b1 = (struct Arista*)b;
    return a1->peso > b1->peso;
}

void KruskalMST(struct Grafo* grafo)
{
    int numVertices = grafo->V;
    struct Arista result[8];
    int e = 0;
    int i = 0;

    qsort(grafo->arista, grafo->E, sizeof(grafo->arista[0]), myComp);

    struct subset* subsets = (struct subset*)malloc(numVertices * sizeof(struct subset));

    for (int x = 0; x < numVertices; ++x)
    {
        subsets[x].parent = x;
        subsets[x].rank = 0;
    }

    while (e < numVertices - 1)
    {
        struct Arista siguiente = grafo->arista[i++];
        int x = find(subsets, siguiente.src);
        int y = find(subsets, siguiente.dest);

        if (x != y)
        {
            result[e++] = siguiente;
            Union(subsets, x, y);
        }
        else {
            //Es un ciclo. Descartar.
        }
    }
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
            result[i].peso);

    return;
}

int main()
{

    int numVertices = 4;
    int numAristas = 5;
    struct Grafo* grafo = createGraph(numVertices, numAristas);

    grafo->arista[0].src = 0;
    grafo->arista[0].dest = 1;
    grafo->arista[0].peso = 10;

    grafo->arista[1].src = 0;
    grafo->arista[1].dest = 2;
    grafo->arista[1].peso = 6;

    grafo->arista[2].src = 0;
    grafo->arista[2].dest = 3;
    grafo->arista[2].peso = 5;

    grafo->arista[3].src = 1;
    grafo->arista[3].dest = 3;
    grafo->arista[3].peso = 15;

    grafo->arista[4].src = 2;
    grafo->arista[4].dest = 3;
    grafo->arista[4].peso = 4;
    KruskalMST(grafo);

    return 0;

}