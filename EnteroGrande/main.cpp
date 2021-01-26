#include <iostream>
#include <conio.h>
#include <string>
#include "Enteros.h"

using namespace std;

int main() {

	Enteros n1("1234567891234");
	Enteros n2("1234567891234");
	n1.Imprimir();
	cout << " + ";
	n2.Imprimir();

	cout << " = ";
	Enteros n3 = n1 + n2;

	_getch();

}