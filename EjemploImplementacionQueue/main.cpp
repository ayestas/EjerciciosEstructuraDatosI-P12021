#include <iostream>
#include <conio.h>
#include "Queue.h"

int main() {
	Queue<int> cola;

	cola.push_back(4);
	cola.push_back(7);
	cola.push_back(3);
	cola.push_back(1);

	cola.print();

	cola.pop_front();

	cola.print();

	_getch();
}