#pragma once
#ifndef QUEUE_H
#define QUEUE_H

template <class T>
struct QueueNode{
	T _data;
	QueueNode<T> _next;
	QueueNode<T> _previous;

	QueueNode(const T& d) {
		_data = d;
		_next = _previous = nullptr;
	}
};

template <class T>
class Queue {
public:
	Queue();

	void push_back(T);
	void pop_back();

	int size();

	bool empty();

	void print();

private:
	QueueNode<T>* first;
	QueueNode<T>* last;
};


#endif // !QUEUE_H
