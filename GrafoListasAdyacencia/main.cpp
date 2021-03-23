#include <iostream>
#include <conio.h>
#include "Grafo.h"
using namespace std;

int main() {
	Grafo a;
	a.insertarNodo(1);
	a.insertarNodo(2);
	a.insertarNodo(3);
	a.insertarNodo(4);
	a.insertarNodo(5);
	a.insertarNodo(6);

	a.insertarAristas(1, 2);
	a.insertarAristas(1, 4);

	a.insertarAristas(2, 5);

	a.insertarAristas(3, 5);
	a.insertarAristas(3, 6);

	a.insertarAristas(4, 2);

	a.insertarAristas(5, 4);

	a.insertarAristas(6, 6);

	cout << "\n\n";
	a.mostrar_grafo();

	_getch();
}