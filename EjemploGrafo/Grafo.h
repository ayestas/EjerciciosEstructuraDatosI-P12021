#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

class Grafo{
public:
	Grafo();
	void agregarVertice(char);
	void agregarArista(char, char);
	void imprimir();

private:
	int nVertices;
	char* vertices;
	int** aristas; //matriz de adyacencia
};

#endif // !GRAFO_H

