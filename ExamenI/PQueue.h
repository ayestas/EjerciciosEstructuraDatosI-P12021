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

template<class T>
PQueue<T>::PQueue() 
	: primero(nullptr), ultimo(nullptr){
}

template<class T>
void PQueue<T>::enqueue(T valor, int priority) {
	Node<T>* nuevo = new Node<T>(valor);

	if (empty()) {
		primero = nuevo;		
	}
	else {

		if (nuevo->data > nuevo->next->data) {
			nuevo->next = primero;
			primero->previous(nuevo);
			primero = nuevo;
		}
		else {
			primero->next = nuevo;
			nuevo->previous(primero);
			nuevo = primero;
		}
	}
}

template<class T>
PQueue<T> PQueue<T>::dequeue() {
	if (empty()) {
		primero = nuevo;
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
	if (empty()) {
		primero = nuevo;
	}

}

template<class T>
void PQueue<T>::Swap(PQueue<T>)
{
}

template<class T>
inline void PQueue<T>::print()
{
}
