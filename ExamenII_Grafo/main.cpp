#include <iostream>
#include <conio.h>
#include "Grafo.h"

using std::cout;

int main() {
	Grafo a;

	a.agregarVertice('A');
	a.agregarVertice('B');
	a.agregarVertice('C');
	a.agregarVertice('D');

	a.agregarArista('A', 'B');
	a.agregarArista('A', 'C');
	a.agregarArista('B', 'C');
	a.agregarArista('C', 'A');
	a.agregarArista('D', 'C');
	a.imprimir();

}