#include "Queue.h"
#include <iostream>

using namespace std;


//template <class T>
//Queue<T>::Queue() 
//: first(nullptr), last(nullptr) {
//
//}
//
////cola circular
//template <class T>
//void Queue<T>::push_back(T _value) {
//	
//	QueueNode<T>* nuevo = new QueueNode<T>(_value);
//
//	if (empty()) {
//		first = last = nuevo;
//		first->_previous = last;
//		last->_next = first;
//	}
//	else {
//		last->_next = nuevo;
//		nuevo->_previous = last;
//
//		last = nuevo;
//
//		last->_next = first;
//		first->_previous = last;
//	}
//}
//
//template <class T>
//void Queue<T>::pop_front() {
//	if (empty()) {
//		return;
//	}
//	if (first == last) {
//		delete first;
//
//		first = last = nullptr;
//	}
//	else {
//		QueueNode<T>* tmp = first;
//
//		first = first->_next;
//		last->_next = first;
//
//		delete tmp;
//	}
//}
//
//template <class T>
//int Queue<T>::size() {
//	if (empty()) {
//		return;
//	}
//
//	int count = 0;
//	QueueNode<T>* actual = first;
//
//	do {
//		count++;
//		actual = actual->_next;
//	} while (actual != first);
//}
//
//template <class T>
//bool Queue<T>::empty() {
//	return first == nullptr;
//}
//
//template <class T>
//void Queue<T>::print() {
//	if (empty()) {
//		return;
//	}
//
//	int count = 0;
//	QueueNode<T>* actual = first;
//
//	do {
//		cout << "[" << actual->_data << " ] ";
//		actual = actual->_next;
//	} while (actual != first);
//
//	cout << "\n";
//}