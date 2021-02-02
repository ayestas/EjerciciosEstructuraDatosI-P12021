#include <iostream>
#include <conio.h>
#include "Queue.h"

using namespace std;

int main() {

	Queue cola;

	cola.push_back(20);
	cola.push_back(15);
	cola.push_back(31);
	cola.push_back(11);
	cola.push_back(7);
	cola.push_back(16);
	cola.push_back(42);

	cola.print();

	cola.pop_front();
	cola.pop_front();

	cola.print();

	_getch();
}