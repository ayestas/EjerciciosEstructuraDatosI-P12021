#include "Grafo.h"
// Bellman Ford Algorithm en C++

int main()
{
	CGrafo g;

	int V = 5; // Vertices
	int A = 8; // Aristas
	struct Grafo* grafo = g.crearGrafo(V, A);

	// Arista 0-1 
	grafo->arista[0].origen = 0;
	grafo->arista[0].destino = 1;
	grafo->arista[0].peso = -1;

	// Arista 0-2 
	grafo->arista[1].origen = 0;
	grafo->arista[1].destino = 2;
	grafo->arista[1].peso = 4;

	// Arista 1-2 
	grafo->arista[2].origen = 1;
	grafo->arista[2].destino = 2;
	grafo->arista[2].peso = 3;

	// Arista 1-3 
	grafo->arista[3].origen = 1;
	grafo->arista[3].destino = 3;
	grafo->arista[3].peso = 2;

	// Arista 1-4 
	grafo->arista[4].origen = 1;
	grafo->arista[4].destino = 4;
	grafo->arista[4].peso = 2;

	// Arista 3-2 
	grafo->arista[5].origen = 3;
	grafo->arista[5].destino = 2;
	grafo->arista[5].peso = 5;

	// Arista 3-1 
	grafo->arista[6].origen = 3;
	grafo->arista[6].destino = 1;
	grafo->arista[6].peso = 1;

	// Arista 4-3 
	grafo->arista[7].origen = 4;
	grafo->arista[7].destino = 3;
	grafo->arista[7].peso = -3;

	g.BellmanFord(grafo, 0);

}