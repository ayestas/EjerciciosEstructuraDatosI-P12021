#pragma once
#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>

using namespace std;

template <class T>
struct Node {
	T data;
	int priority;
	Node<T>* next;
	Node<T>* previous;

	Node(const T& _data, int _priority) {
		data = _data;
		_priority = priority;
		next = nullptr;
		previous = nullptr;
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

template<class T>
PQueue<T>::PQueue() 
	: primero(nullptr), ultimo(nullptr){
}

template<class T>
void PQueue<T>::enqueue(T valor, int priority) {
	Node<T>* nuevo = new Node<T>(valor, priority);

	if (isEmpty()) {
		primero = nuevo;		
	}
	else {
		Node<T>* actual = primero;

		while (actual != nullptr) 	{
			actual = actual->next;
		}

		actual->next = nuevo;
			
	}
}

template<class T>
PQueue<T> PQueue<T>::dequeue() {
	if (isEmpty()) {
		return;
	}

	if (primero = ultimo) {
		delete primero;
		primero = ultimo = nullptr;
	}
	else {
		Node<T>* tmp = primero;

		return tmp;
		primero = primero->next;
		delete tmp;
	}
}

template<class T>
bool PQueue<T>::isEmpty() {
	return primero = nullptr;
}

template<class T>
int PQueue<T>::getCountPriorities(int priority) {
	if (isEmpty()) {
		primero = nullptr;
	}

	int count = 0;
	Node<T>* actual = primero;
	do {
		if (actual->priority == priority) {
			count++;
		}
		actual = actual->next;

	} while (actual != nullptr);

}

template<class T>
void PQueue<T>::Swap(PQueue<T> a) {
	if (isEmpty()) {
		primero = a.primero = nullptr;
	}

	Node<T>* actual = primero;

	do {
		actual = a.primero;
		a.primero = actual;

		actual = actual->next;
		a.primero = primero->next;

	} while (actual != nullptr);
}

template<class T>
inline void PQueue<T>::print() {
	if (isEmpty()) {
		return;
	}
	Node<T>* actual = primero;

	do {
		cout << "[" << actual << " ] ";
		actual = actual->next;
	} while (actual != primero);

	cout << "\n";
}
