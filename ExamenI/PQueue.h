#pragma once
#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>

template <class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* previous;

	Node(const T& _data, int _priority) {
		data = _data;
		_priority = 0;
		next = previous = nullptr;
	}
};

template <class T>
class PQueue {
public:
	PQueue();

	void enqueue(T, int);
	PQueue<T> dequeue();

	bool isEmpty();

	int getCountPriorities(int);

	void Swap(PQueue<T>);

	void print();


private:
	Node<T>* primero;
	Node<T>* ultimo;
};

#endif // !PQUEUE_H

