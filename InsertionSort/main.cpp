#include <conio.h>
#include <iostream>

using namespace std;

int main() {

	int numeros[] = { 0,4,2,3,1,5,6 };
	int posActual, aux;
	int sizeA = sizeof(numeros) / sizeof(numeros[0]);

	//Ordenamiento por Insercion
	for (int x = 0; x < sizeA; x++) {
		posActual = x;
		aux = numeros[x];

		while ((posActual > 0) && (numeros[posActual - 1] > aux)) {
			numeros[posActual] = numeros[posActual - 1];
			posActual--;
		}
		numeros[posActual] = aux;
	}
	//
	cout << "Cantidad de elementos: " << sizeA << endl;
	cout << "Arreglo ordenado: ";
	for (int x = 0; x < sizeA; x++) {
		cout << "[ " << numeros[x] << " ] ";
	}

	_getch();
}