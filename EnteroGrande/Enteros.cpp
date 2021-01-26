#include "Enteros.h"
#include <iostream>
#include <sstream>

using namespace std;

Enteros& operator+(const Enteros& a, const Enteros& b) {
	Enteros resultado;
	int num1, num2;
	

	for (int i = 0; i < a.elementos; i++) {
		num1 = a.digitos[i];
	}

	for (int i = 0; i < b.elementos; i++) {
		num2 = b.digitos[i];
	}

	return resultado;
}

Enteros::Enteros() 
	: digitos(0) {
}

Enteros::Enteros(std::string num)
	: digitos(0){
	elementos = num.size();
	digitos = new int[elementos];

	for (int i = 0; i < num.size(); i++) {
		digitos[i] = ((int)num.at(i)) - 48;
	}
}

void Enteros::Imprimir() {
	for (int i = 0; i < elementos; i++) {
		cout << digitos[i];
	}
}
