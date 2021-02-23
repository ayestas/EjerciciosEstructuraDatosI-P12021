#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

using std::cout;

template <class T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode<T>* rightChild;
	BinaryTreeNode<T>* leftChild;

	BinaryTreeNode(const T& _data, BinaryTreeNode<T>* _rChild, BinaryTreeNode<T>* _lChild) {
		data = _data;
		rightChild = _rChild;
		leftChild = _lChild;
	}
};

template <class T>
class BinaryTree {
public:
	BinaryTree() : root(nullptr) {}

	void addNode(T);
	void deleteNode(T);

	//Trasverse Tree
	void printPreOrden();
	void printInOrden();
	void printPosOrden();

	bool search(T);

private:
	BinaryTreeNode<T>* root;

	BinaryTreeNode<T>* addNodeRec(BinaryTreeNode<T>*, T);
	void printPreOrdenRec(BinaryTreeNode<T>*);
	void printInOrdenRec(BinaryTreeNode<T>*);
	void printPosOrdenRec(BinaryTreeNode<T>*);
};

#endif // !BINARY_TREE_H

template<class T>
void BinaryTree<T>::addNode(T _data) {
	root = addNodeRec(root, _data);
}

template<class T>
void BinaryTree<T>::deleteNode(T) {

}

//raiz, izquierda, derecha
template<class T>
void BinaryTree<T>::printPreOrden() {
	printPreOrdenRec(root);
}

//izquierda, raiz, derecha
template<class T>
void BinaryTree<T>::printInOrden() {
	printInOrdenRec(root);
}

//izquierda, derecha, raiz
template<class T>
void BinaryTree<T>::printPosOrden() {
	printPosOrdenRec(root);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::addNodeRec(BinaryTreeNode<T>* _root, T _data) {
	if (_root == nullptr) {
		BinaryTreeNode<T>* nuevo = new BinaryTreeNode<T>(_data, nullptr, nullptr);
		_root = nuevo;
	}
	else if (_data > _root->data) {
		//Enviar el nodo al subarbol derecho
		_root->rightChild = addNodeRec(_root->rightChild, _data);
	}
	else if (_data < _root->data) {
		_root->leftChild = addNodeRec(_root->leftChild, _data);

	}

	return _root;
}

template<class T>
void BinaryTree<T>::printPreOrdenRec(BinaryTreeNode<T>* _root) {
	if (_root == nullptr) {
		return;
	}

	cout << "[ " << _root->data << " ] ";
	printPreOrdenRec(_root->leftChild);
	printPreOrdenRec(_root->rightChild);
}

template<class T>
void BinaryTree<T>::printInOrdenRec(BinaryTreeNode<T>* _root) {
	if (_root == nullptr) {
		return;
	}

	printInOrdenRec(_root->leftChild);
	cout << "[ " << _root->data << " ] ";
	printInOrdenRec(_root->rightChild);
}

template<class T>
void BinaryTree<T>::printPosOrdenRec(BinaryTreeNode<T>* _root) {

}
