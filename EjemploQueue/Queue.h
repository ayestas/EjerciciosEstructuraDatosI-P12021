#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <list>
#include <iostream>

using namespace std;

class Queue {
public:
	Queue ();

	void push_back(int);
	void pop_front();

	int size();
	bool isEmpty();
	int getFront();
	int getBack();

	void print();

private:
	list<int> items;

};

#endif // !QUEUE_H

