#include "GrafoPonderado.h"
#include <iostream>
#include <iomanip>

#define INF 9999

using namespace std;

GrafoPonderado::GrafoPonderado() : nVertices(0), vertices(nullptr), aristas(nullptr)
{}

void GrafoPonderado::agregarVertice(char _vertice)
{
	char* verticesCpy = new char[nVertices + 1];
	for (int i = 0; i < nVertices; i++)
		verticesCpy[i] = vertices[i];

	verticesCpy[nVertices] = _vertice;

	if (vertices != nullptr)
		delete vertices;

	vertices = verticesCpy;

	int** aristasCpy = new int* [nVertices + 1];

	for (int i = 0; i < nVertices; i++)
		aristasCpy[i] = aristas[i];

	if (aristas != nullptr)
		delete aristas;

	aristas = aristasCpy;

	for (int i = 0; i < nVertices; i++)
	{
		int* aristaColumnaCopy = new int[nVertices + 1];

		for (int j = 0; j < nVertices; j++)
			aristaColumnaCopy[j] = aristas[i][j];

		if (aristas[i] != nullptr)
			delete aristas[i];

		aristaColumnaCopy[nVertices] = 0;

		aristas[i] = aristaColumnaCopy;
	}

	aristas[nVertices] = new int[nVertices + 1];

	for (int i = 0; i < nVertices + 1; i++)
	{
		if (i == nVertices)
			aristas[nVertices][i] = 0;
		else
		{
			aristas[nVertices][i] = INF;
			aristas[i][nVertices] = INF;
		}
	}

	nVertices++;
}

void GrafoPonderado::agregarArista(char verticeOrigen, char verticeDestino, int weight)
{
	int indiceOrigen = obtenerIndiceVertice(verticeOrigen);
	int indiceDestino = obtenerIndiceVertice(verticeDestino);

	if (indiceOrigen != -1 && indiceDestino != -1)
		aristas[indiceOrigen][indiceDestino] = weight;
}

void GrafoPonderado::imprimir()
{
	cout << "Vertices: { ";
	for (int i = 0; i < nVertices; i++)
	{
		if (i != nVertices - 1)
			cout << vertices[i] << ", ";
		else
			cout << vertices[i];
	}
	cout << "}" << endl;

	cout << endl << "Aristas: " << endl;
	cout << " ";

	for (int i = 0; i < nVertices; i++)
		cout << "\t" << vertices[i];

	cout << endl;

	for (int i = 0; i < nVertices; i++)
	{
		cout << vertices[i];
		for (int j = 0; j < nVertices; j++)
		{
			if (aristas[i][j] == INF)
				cout << "\t" << "[" << "INF" << "] ";
			else
				cout << "\t" << "[" << aristas[i][j] << "] ";
		}


		cout << std::endl;
	}
}

void GrafoPonderado::floydWarshall()
{
	cout << endl << "Distancia mas corta entre dos vertices" << endl << "Algoritmo Floyd-Warshall" << endl;
	/*int** distancias sera el grafo solucion, indicando la distancia mas corta entre cada uno de los pares de vertices*/
	int** distancias = new int* [nVertices];
	int i, j, k;

	/*Se inicializa el grafo de solucion (distancias) igual que el grafo inicial, se podria decir que entonces las distancias minimas en este caso no consideran los vertices entre dos puntos*/
	for (i = 0; i < nVertices; i++)
		distancias[i] = aristas[i];

	for (i = 0; i < nVertices; i++)
	{
		distancias[i] = new int[nVertices];
		for (j = 0; j < nVertices; j++)
		{
			distancias[i][j] = aristas[i][j];
		}
	}

	/*Primero se añaden todos los vertices uno por uno a los vertices intermedios*/
	/*Antes de iniciar una iteracion del ciclo, tendremos la distancia mas corta entre todos*/
	for (k = 0; k < nVertices; k++)
	{
		for (i = 0; i < nVertices; i++)
		{
			for (j = 0; j < nVertices; j++)
			{
				if (distancias[i][k] + distancias[k][j] < distancias[i][j])
					distancias[i][j] = distancias[i][k] + distancias[k][j];
			}
		}
	}

	/*Imprimir grafo solucion*/
#pragma region Imprimir-Grafo-Solucion
	cout << endl << "Distancia Mas Corta entre Vertices: " << endl;
	cout << " ";
	for (int i = 0; i < nVertices; i++)
		cout << "\t" << vertices[i];
	cout << endl;
	for (int i = 0; i < nVertices; i++)
	{
		cout << vertices[i];
		for (int j = 0; j < nVertices; j++)
		{
			if (distancias[i][j] == INF)
				cout << "\t" << "[INF] ";
			else
				cout << "\t" << "[" << distancias[i][j] << "] ";
		}
		cout << std::endl;
	}
#pragma endregion
}

int GrafoPonderado::obtenerIndiceVertice(char _vertice)
{
	for (int i = 0; i < nVertices; i++)
		if (vertices[i] == _vertice)
			return i;

	return -1;
}