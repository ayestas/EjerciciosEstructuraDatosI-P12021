#include <iostream>
#include <conio.h>
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

	tree.printInOrden();

	tree.search(56);

	if (tree.esLista()) {
		cout << "\nEs lista!!";
	}
	else {
		cout << "\nNo es lista!!";
	}


	cout << "\n";

	_getch();
}