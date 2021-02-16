#include "Locker.h"
#include <iostream>

Locker::Locker(int _tamanio) :Tamanio(_tamanio) {
	arrayLockers = new int[_tamanio];
}

//Devuelve la posicion en el arreglo del valor que se busca, de no estar en el arreglo se devuelve -1
int Locker::linearSearch(int valor) {
	for (int i = 0; i < Tamanio; i++) {
		if (valor == arrayLockers[i]) {
			return i;
		}
	}
	return -1;
}


void Locker::imprimir() {
	for (int i = 0; i < Tamanio; i++) {
		std::cout << "[" << arrayLockers[i] << "]";
	}
	std::cout << std::endl;
}