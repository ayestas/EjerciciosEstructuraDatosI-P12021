#include "Grafo.h"
#include <limits.h>
#include <iostream>

struct Grafo* CGrafo::crearGrafo(int V, int A)
{
	struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));

	grafo->numVertices = V;
	grafo->numAristas = A;

	grafo->arista = (struct Arista*)malloc(grafo->numAristas * sizeof(struct Arista));

	return grafo;
}


void CGrafo::BellmanFord(struct Grafo* grafo, int _origen)
{
	int numVertices = grafo->numVertices;
	int numAristas = grafo->numAristas;
	int* dist = new int[numVertices];

	// Paso 1
	for (int i = 0; i < numVertices; i++)
	{
		dist[i] = INT_MAX;
	}

	dist[_origen] = 0;

	// Paso 2
	for (int i = 1; i <= numVertices - 1; i++)
	{
		for (int j = 0; j < numAristas; j++)
		{
			int vOrigen = grafo->arista[j].origen;
			int vDestino = grafo->arista[j].destino;
			int peso = grafo->arista[j].peso;

			if (dist[vOrigen] != INT_MAX && dist[vOrigen] + peso < dist[vDestino])
			{
				dist[vDestino] = dist[vOrigen] + peso;
			}
		}
	}

	// Paso 3
	for (int i = 0; i < numAristas; i++)
	{
		int vOrigen = grafo->arista[i].origen;
		int vDestino = grafo->arista[i].destino;
		int peso = grafo->arista[i].peso;
		if (dist[vOrigen] != INT_MAX && dist[vOrigen] + peso < dist[vDestino])
			std::cout << "Grafo contiene un ciclo de peso negativo";
	}

	print(dist, numVertices);

	return;
}


void CGrafo::print(int dist[], int n)
{
	printf("Vertice   Distancia del origen\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}