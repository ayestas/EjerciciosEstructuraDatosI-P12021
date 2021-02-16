#include <iostream>
#include <conio.h>
#include "PQueue.h"

using namespace std;

int main() {
	PQueue<int> c1;

	c1.enqueue(1, 30);
	c1.enqueue(7, 10);
	c1.enqueue(3, 20);
	c1.enqueue(9, 40);

	c1.print();

	_getch();
}