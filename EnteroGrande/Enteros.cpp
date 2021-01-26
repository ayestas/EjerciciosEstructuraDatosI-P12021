#include "Enteros.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <functional>

using namespace std;

Enteros& operator+(const Enteros& a, const Enteros& b) {
	Enteros resultado;
	int num1, num2;
	vector<int> number1;
	vector<int> number2;

	for (int i = 0; i < a.elementos; i++) {
		num1 = a.digitos[i];
		number1.push_back(num1);
	}

	for (int j = 0; j < b.elementos; j++) {
		num2 = b.digitos[j];
		number2.push_back(num2);
	}

	std::transform(number1.begin(), number1.end(), number2.begin(), number1.begin(), std::plus<int>());

	for (std::vector<int>::iterator it = number1.begin(); it != number1.end(); ++it) {
		cout << *it;
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
