#include "Grafo.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

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

void Grafo::agregarArista(char verticeOrigen, char verticeDestino) {
	int indiceOrigen = obtenerIndiceVertice(verticeOrigen);
	int indiceDestino = obtenerIndiceVertice(verticeDestino);

	if (indiceOrigen != -1 && indiceDestino != -1) {
		//grafo dirigido
		aristas[indiceOrigen][indiceDestino] = 1;
		//grafo no dirigido
		aristas[indiceDestino][indiceOrigen] = 1;
	}
}

void Grafo::imprimir() {

	cout << "Vertices:{ ";
	for (int i = 0; i < nVertices; i++) {

		if (i != nVertices - 1) {
			cout << vertices[i] << ", ";
		}
		else {
			cout << vertices[i];
		}
	}
	cout << "}\n";

	cout << "\nAristas: \n";
	cout << setw(3) << " ";
	for (int i = 0; i < nVertices; i++) {
		cout << setw(3) << " " << vertices[i] << "  ";
	}
	cout << "\n";

	for (int x = 0; x < nVertices; x++) {
		cout << setw(3) << vertices[x];
		for (int i = 0; i < nVertices; i++) {
			cout << setw(3) << "[ " << aristas[x][i] << " ]";
		}
		cout << endl;
	}
}

vector<vector<char>> Grafo::obtenerListaAdy() {
	vector<vector<char>> LA(nVertices);

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			//Empezar a insertar al vector
			if (aristas[i][j] != 0) {
				LA[i].push_back(vertices[j]);
			}
		}
	}

	return LA;
}

void Grafo::imprimirListaAdy() {
	vector<vector<char>> LA(nVertices);

	cout << "Vertices:{ ";
	for (int i = 0; i < nVertices; i++) {

		if (i != nVertices - 1) {
			cout << vertices[i] << ", ";
		}
		else {
			cout << vertices[i];
		}
	}
	cout << "}\n";

	cout << "\nAristas: \n";
	cout << setw(3) << " ";
	for (int i = 0; i < nVertices; i++) {
		cout << setw(3) << " " << vertices[i] << "  ";
	}
	cout << "\n";

	for (int x = 0; x < nVertices; x++) {
		cout << setw(3) << vertices[x];
		for (int i = 0; i < nVertices; i++) {
			cout << setw(3) << "[ " << aristas[x][i] << " ]";
		}
		cout << endl;
	}
}

int Grafo::obtenerIndiceVertice(char _vertice) {
	for (int i = 0; i < nVertices; i++) {
		if (vertices[i] == _vertice)
			return i;
	}

	return -1;
}

