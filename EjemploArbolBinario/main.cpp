#include <conio.h>
#include <iostream>
#include "BinaryTree.h"

using std::cout;

int main() {
	BinaryTree<int> tree;

	tree.addNode(40);
	tree.addNode(22);
	tree.addNode(56);
	tree.addNode(63);
	tree.addNode(16);
	tree.addNode(44);

	tree.printPreOrden();
	cout << "\n";
	tree.printInOrden();
	cout << "\n";
	tree.printPosOrden();

	_getch();
}