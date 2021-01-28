#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
//Definicion de cada nodo

template <class T>
struct StackNode {
	T data;
	StackNode <T>* next;
	StackNode <T>* previous;
	StackNode(const T& _data, StackNode<T>* _next, StackNode<T>* _previous) {
		data = _data;
		next = _next;
		previous = _previous;
	}
};

template <class T>
class Stack {
public:
	//forma predeterminada tendria un limite de 10 elementos
	Stack(int cantidadElementos = 10) : top(nullptr), items(cantidadElementos) {};
	//Stack() : top(nullptr) {};

	bool isEmpty();
	void push(T);
	void pop();

	T& peek();

	void print();

private:
	StackNode<T>* top;
	int items;

	int countItems();

};

template <class T>
bool Stack<T>::isEmpty() {
	return top == nullptr;
}

template <class T>
void Stack<T> ::push(T _data) {
	if (countItems() >= items) {
		cout << "Imposible insertar. Se ha alcanzado el limite de la Pila!\n\n";
		return;
	}


	StackNode<T>* nuevo = new StackNode<T>(_data, nullptr, nullptr);
	/*forma 2
	nuevo->data = _data;
	nuevo->next = nullptr;
	nuevo->previous = nullptr;
	*/
	if (isEmpty()) {
		top = nuevo;
	}
	else {
		nuevo->next = top;
		top->previous = nuevo;
		top = nuevo;
	}
}

template <class T>
void Stack<T> ::print() {
	StackNode<T>* actual = top;
	cout << "Cantidad de elementos: " << countItems() << "\n";

	while (actual != nullptr) {
		cout << "[ " << actual->data << "]\n";
		actual = actual->next;
	}
}

template <class T>
void Stack<T>::pop() {
	if (isEmpty()) {
		return;
	}

	StackNode<T>* actual = top;

	top = top->next;
	top->previous = nullptr;

	delete actual;
}

template <class T>
T& Stack<T>::peek() {
	return top->data;
}

template <class T>
int Stack<T>::countItems() {
	if (isEmpty()) {
		return 0;
	}

	StackNode<T>* actual = top;
	int cantidad = 0;

	while (actual != nullptr) {
		cantidad++;
		actual = actual->next;
	}

	return cantidad;
}
#endif // !STACK_H
