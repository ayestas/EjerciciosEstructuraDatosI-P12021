#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>

using namespace std;

int main() {
	srand((unsigned)time(0));
	int tamaño = 10;

	int* A = nullptr;
	A = new int[10];

	vector<int> V;

	for (int i = 0; i < tamaño; i++) {
		int valorV = (rand() % 100) + 1;
		int valorA = (rand() % 100) + 1;

		V.push_back(valorV);
		A[i] = valorA;
	}

	for (int i = 0; i < V.size(); i++) {
		cout << "vector [" << i << "] = { " << &V[i] << ", " << V[i] << " }\n";
	}

	cout << "\n";

	for (int i = 0; i < 10; i++) {
		cout << "array [" << i << "] = { " << &A[i] << ", " << A[i] << " }\n";
	}

	_getch();
}