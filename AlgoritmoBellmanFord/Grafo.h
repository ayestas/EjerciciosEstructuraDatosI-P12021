#pragma once

#ifndef GRAFO_H
#define GRAFO_H

struct Arista
{
	int origen, destino, peso;
};

struct Grafo
{
	int numVertices = 0, numAristas = 0;
	struct Arista* arista;
};

class CGrafo
{

public:
	void BellmanFord(struct Grafo* grafo, int _origen);
	struct Grafo* crearGrafo(int V, int A);

private:
	void print(int dist[], int v);

};


#endif // !GRAFO_H