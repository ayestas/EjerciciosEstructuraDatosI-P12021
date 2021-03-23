#include "Grafo.h"
#include <iostream>
#include <iomanip>
#include <vector>
using std::setw;
using namespace std;
#define V 5
Grafo::Grafo() : nVertices(0), vertices(nullptr), aristas(nullptr) {

}

void Grafo::agregarVertice(char _verticeID) {
	char* verticesCopy = new char[nVertices + 1];

	for (int i = 0; i < nVertices; i++) {
		verticesCopy[i] = vertices[i];
	}

	verticesCopy[nVertices] = _verticeID;

	if (vertices != nullptr)
		delete vertices;

	vertices = verticesCopy;

	//actualizacion de filas en aristas

	//actualiza el numero de filas
	int** aristasCpy = new int* [nVertices + 1];

	for (int i = 0; i < nVertices; i++)
	{
		aristasCpy[i] = aristas[i];
	}

	if (aristas != nullptr)
		delete aristas;

	aristas = aristasCpy;

	//Actualizacion de columnas en aristas

	//por cada fila del arreglo de aristas

	for (int i = 0; i < nVertices; i++)
	{
		int* aristaColumnaCpy = new int[nVertices + 1];


		for (int j = 0; j < nVertices; j++)
		{
			aristaColumnaCpy[j] = aristas[i][j];
		}

		if (aristas[i] != nullptr)
			delete aristas[i];

		aristaColumnaCpy[nVertices] = 0;

		aristas[i] = aristaColumnaCpy;
	}

	//ultima fila de aristas

	aristas[nVertices] = new int[nVertices + 1];
	for (int i = 0; i < nVertices + 1; i++)
	{
		aristas[nVertices][i] = 0;
	}

	nVertices++;

}

void Grafo::agregarArista(char verticeOrigen, char verticeDestino, int peso) {
	int indiceOrigen = obtenerIndiceVertice(verticeOrigen);
	int indiceDestino = obtenerIndiceVertice(verticeDestino);

	if (indiceOrigen != -1 && indiceDestino != -1) {
		aristas[indiceOrigen][indiceDestino] = peso;
	}
}

int Grafo::obtenerIndiceVertice(char _vertice) {
	for (int i = 0; i < nVertices; i++) {
		if (vertices[i] == _vertice) {
			return i;
		}
	}
	return -1;
}

void Grafo::imprimir() {
	cout << std::setw(4) << "  ";

	for (int k = 0; k < nVertices; k++) {
		cout << std::setw(5) << vertices[k] << " ";
	}
	cout << "\n";

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			if (j == 0)
				cout << std::setw(4) << vertices[i];

			cout << std::setw(4) << "[" << aristas[i][j] << "]";
		}
		cout << endl;
	}
	cout << "\n\n";
}

vector< vector<int> > Grafo::prim() {
	/*Copia de la matriz de adyacencia en un vector, para optimizar el proceso.*/
	vector< vector<int> > adyacencia = toVector();

	/*De igual manera se crea el arbol recubridor donde guardaremos los mejores caminos.*/
	vector< vector<int> > arbol(nVertices);

	/*Un vector que guaradara los caminos ya visitados.*/
	vector<char> vistos;

	// Inicializo las distancias del arbol en 0 o Infinito.
	for (int i = 0; i < nVertices; i++) {
		arbol[i] = vector<int>(nVertices, 0);
	}

	/*El minimo que puede ser la cantidad maxima dentro del grafo o un numero exageramente
	grande, fila y columna que guaradara la fila y columna que esta siendo visitada y peso
	que guarda el peso total del grafo.*/
	int fila = 0;
	int columna = 0;
	int peso = 0;
	int minimo = 60000;

	/*Este ciclo se repite las veces que sea necesario hasta que se visiten todos los nodos
	del grafo y se determine el camino mas corto para llegar a ellos.*/
	while (vistos.size() < nVertices) {
		/*Este es el ciclo que hace la eficiencia del algoritmo n^2 porque revisa el grafo
		n*n veces para encontrar el minimo*/
		for (int i = 0; i < nVertices; i++) {
			for (int j = 0; j < nVertices; j++) {
				if (minimo > adyacencia[fila][j] && adyacencia[fila][j] != 0) {
					minimo = adyacencia[fila][j];
					columna = j;
				}
			}
			if (minimo == 60000)
				minimo = 0;
		}


		/*Agrego a Vistos los vertices vistos y agrego al arbol recubridor la distancia mas corta,
		paso a la siguiente fila y sumo el minimo al peso total del arbol, establesco el minimo denuevo a 6000.*/
		vistos.push_back(vertices[fila]);
		arbol[fila][columna] = minimo;
		arbol[columna][fila] = minimo;
		peso += minimo;
		fila++;
		minimo = 60000;
	}

	cout << "\nEL PESO DEL ARBOL RECUBRIDO ES DE: " << peso << "\n";
	return arbol;
}


void Grafo::imprimirArbol(vector< vector<int>> matriz) {
	cout << std::setw(4) << "  ";

	for (int k = 0; k < nVertices; k++) {
		cout << std::setw(5) << vertices[k] << " ";
	}
	cout << "\n";

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			if (j == 0)
				cout << std::setw(4) << vertices[i];

			cout << std::setw(4) << "[" << matriz[i][j] << "]";
		}
		cout << endl;
	}
	cout << "\n\n";
}

vector<vector<int>> Grafo::toVector() {
	vector< vector<int>> matriz;
	matriz = vector< vector<int> >(nVertices);
	int peso = 0;

	for (int i = 0; i < nVertices; i++)
		matriz[i] = vector<int>(nVertices);

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			if (aristas[i][j] != 0) {
				matriz[i][j] = aristas[i][j];
				peso += aristas[i][j];
			}
			else
				matriz[i][j] = INT_MAX;
		}
	}

	cout << "\nEL PESO DEL GRAFO INICIAL ES DE: " << peso / 2 << "\n";
	return matriz;
}