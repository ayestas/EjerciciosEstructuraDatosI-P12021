#include "Grafo.h"

Grafo::Grafo()
: nVertices(0), vertices(nullptr), aristas(nullptr) {
}

void Grafo::agregarVertice(char _verticeID) {
	char* verticesCpy = new char[nVertices + 1];

	for (int i = 0; i < nVertices; i++)
		verticesCpy[i] = vertices[i];

	verticesCpy[nVertices] = _verticeID;

	if (vertices != nullptr)
		delete vertices;

	vertices = verticesCpy;

	//Actualizacion de filas en aristas

	//actuaiza el numero de filas
	int** aristasCpy = new int* [nVertices + 1];

	for (int i = 0; i < nVertices; i++)
		aristasCpy[i] = aristas[i];

	if (aristas != nullptr)
		delete aristas;

	aristas = aristasCpy;

	for (int i = 0; i < nVertices; i++) {
		int* aristaColumnaCpy = new int[nVertices + 1];

		for (int j = 0; j < nVertices; j++) 
			aristaColumnaCpy[j] = aristas[i][j];

		if (aristas[i] != nullptr)
			delete aristas[i];

		aristaColumnaCpy[nVertices] = 0;

		aristas[i] = aristaColumnaCpy;
	}

	//ultima fila de aristas
	aristas[nVertices] = new int[nVertices + 1];
	for (int i = 0; i < nVertices + 1; i++)
		aristas[nVertices][i] = 0;

	nVertices++;
}

void Grafo::agregarArista(char, char) {

}

void Grafo::imprimir() {

}

