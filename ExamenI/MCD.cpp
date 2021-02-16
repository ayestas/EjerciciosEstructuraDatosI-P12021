#include <iostream>
#include <conio.h>

using namespace std;

int MCD(int num1, int num2) {
	if (num1 < num2) {
		return MCD(num2, num1);
	}
	else if (num2 == 0) {
		return num1;
	}
	else {
		return MCD(num2, int(num1 % num2));
	}
}

//int main() {
//	int num1, num2;
//	cout << "*** MAXIMO COMÚN DIVISOR ***\n\nIngrese el primer numero: ";
//	cin >> num1;
//	cout << "\nIngrese el segundo numero: ";
//	cin >> num2;
//
//	cout << "MCD: " << MCD(num1, num2);
//
//}
