#pragma once
#ifndef GRAFO_PONDERADO_H
#define GRAFO_PONDERADO_H

class GrafoPonderado
{
public:
	GrafoPonderado();
	void agregarVertice(char _vertice);
	void agregarArista(char verticeOrigen, char verticeDestino, int weight);
	void imprimir();
	void floydWarshall();
private:
	int nVertices;
	char* vertices;
	int** aristas;
	int obtenerIndiceVertice(char);
};

#endif // !GRAFO_PONDERADO_H