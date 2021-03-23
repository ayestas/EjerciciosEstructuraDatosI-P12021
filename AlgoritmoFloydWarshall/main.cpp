#include <conio.h>
#include "GrafoPonderado.h"

int main()
{
	GrafoPonderado grafo;

	grafo.agregarVertice('A');
	grafo.agregarVertice('B');
	grafo.agregarVertice('C');
	grafo.agregarVertice('D');

	grafo.agregarArista('A', 'B', 3);
	grafo.agregarArista('B', 'A', 2);
	grafo.agregarArista('A', 'D', 5);
	grafo.agregarArista('B', 'D', 4);
	grafo.agregarArista('C', 'B', 1);
	grafo.agregarArista('D', 'C', 2);

	grafo.imprimir();

	grafo.floydWarshall();
	_getch();
}