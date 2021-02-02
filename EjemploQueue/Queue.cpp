#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() { }

void Queue::push_back(int _value) {
	items.push_back(_value);
}

void Queue::pop_front() {
	items.pop_front();
}

int Queue::size() {
	return items.size();
}

bool Queue::isEmpty() {
	return items.empty();
}

int Queue::getFront() {
	return items.front();
}

int Queue::getBack() {
	return items.back();
}

void Queue::print() {
	cout << "size: " << size() << "\n";
	
	for (int valor : items) {
		cout << "[ " << valor << " ] ";
	}

	cout << "\n";
}
