#include <iostream>
#include <conio.h>

using namespace std;

struct employee {
	//size of 4 bytes
	int codigo;
	//size of 20 bytes
	char nombre[20];
	//size of 4 bytes
	float salary;
	//size of 1 byte
	bool status;

	//total size of 29
};

int main() {
	int* numbers;
	numbers = new int[10];

	for (int i = 0; i < 10; i++) {
		numbers[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		cout << "Numbers[" << i << "]: { " << numbers[i] << ", " << &numbers[i] << " }\n";
	}

	//_________________________________________________________________________________________________

	cout << "\n";

	char* name;
	name = new char[20];

	strcpy_s(name, strlen("Hola Mundo") + 1, "Hola Mundo");

	for (int i = 0; i < strlen(name); i++) {
		cout << "Name[" << i << "]: { " << name[i] << ", " << (void*)&name[i] << " }\n";
	}

	//_________________________________________________________________________________________________

	cout << "\n";

	employee list[10];

	for (int i = 0; i < 10; i++) {
		cout << "Employee[" << i << "]: Adress:  " << &list[i] << " \n";

	}

	_getch();
}