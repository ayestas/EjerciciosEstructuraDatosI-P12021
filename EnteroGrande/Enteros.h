#pragma once
#ifndef ENTEROS_H
#define ENTEROS_H	
#include <string>

using namespace std;

class Enteros {
	friend std::ostream& operator<<(std::ostream&, const Enteros&);
	friend Enteros& operator+(const Enteros&, const Enteros&);

public:
	Enteros();
	Enteros(string);
	void Imprimir();

private:
	int* digitos;
	int elementos;
	int total;

};

#endif // !ENTEROS_H

