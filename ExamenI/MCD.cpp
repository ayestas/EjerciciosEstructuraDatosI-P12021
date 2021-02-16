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

