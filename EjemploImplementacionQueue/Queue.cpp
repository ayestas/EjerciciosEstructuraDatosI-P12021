#include "Queue.h"

template <class T>
Queue<T>::Queue() 
: first(nullptr), last(nullptr) {

}

//cola circular
template <class T>
void Queue<T>::push_back(T _value) {
	
	QueueNode<T>* nuevo = new QueueNode<T>(_value);

	if (empty()) {
		first = last = nuevo;
		first->_previous = last;
		last->_next = first;
	}
	else {
		last->_next = nuevo;
		nuevo->_previous = last;

		last = nuevo;

		last->_next = first;
		first->_previous = last;
	}
}

template <class T>
void Queue<T>::pop_back() {

}

template <class T>
int Queue<T>::size();

template <class T>
bool Queue<T>::empty() {
	return first == nullptr;
}

template <class T>
void Queue<T>::print() {

}