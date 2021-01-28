//#include "Stack.h"
//#include <iostream>
//using namespace std;
//
//template <class T>
//bool Stack<T>::isEmpty() {
//	return top == nullptr;
//}
//
//template <class T>
//void Stack<T> ::push(T _data){
//	StackNode<T>* nuevo = new StackNode<T>(_data,nullptr,nullptr);
//	/*forma 2
//	nuevo->data = _data;
//	nuevo->next = nullptr;
//	nuevo->previous = nullptr;
//	*/
//	if (isEmpty()) {
//		top = nuevo;
//	}
//	else {
//		nuevo->next=top;
//		top->previous = nuevo;
//		top = nuevo;
//	}
//}
//
//template <class T>
//void Stack<T> ::print() {
//	StackNode<T>* actual = top;
//	while (actual != nullptr) {
//		cout << "[ "<<actual->data <<"]\n";
//		actual = actual->next;
//	}
//}