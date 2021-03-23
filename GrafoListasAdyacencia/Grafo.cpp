#include "Grafo.h"

Grafo::Grafo() :raiz(nullptr) {
}

bool Grafo::Vacio() {
	return raiz == nullptr;
}

void Grafo::insertarNodo(int _dato) {
	Nodo* nuevo = new Nodo(_dato);
	if (Vacio()) {
		raiz = nuevo;
	}
	else {
		Nodo* tmp = raiz;

		while (tmp->siguiente != nullptr) {
			tmp = tmp->siguiente;
		}
		tmp->siguiente = nuevo;
	}
}


void Grafo::insertarAristas(int _inicio, int _fin) {

	if (Vacio()) {
		cout << "GRAFO VACIO...!!!!\n";
		return;
	}

	Nodo* aux = raiz;
	Nodo* aux2 = raiz;

	while (aux2 != nullptr) {
		if (aux2->dato == _fin) {
			break;
		}
		aux2 = aux2->siguiente;
	}

	if (aux2 == nullptr) {
		cout << "No se econtro el Vertice: " << _fin << "\n";
		return;
	}

	while (aux != nullptr) {

		if (aux->dato == _inicio) {
			agrega_arista(aux, aux2);
			return;
		}
		aux = aux->siguiente;
	}
	if (aux == nullptr) {
		cout << "No se econtro el Vertice: " << _inicio << "\n";
		return;
	}
}

void Grafo::agrega_arista(Nodo* origen, Nodo* destino) {

	Aristas* nuevo = new Aristas();

	if (origen->adyaciencia == nullptr) {

		nuevo->vertice = destino;

		origen->adyaciencia = nuevo;
		/*aux->adyaciencia->vertice = aux2;*/
	}
	else {

		Aristas* tmp;

		tmp = origen->adyaciencia;

		while (tmp->siguiente != nullptr)
			tmp = tmp->siguiente;

		nuevo->vertice = destino;
		tmp->siguiente = nuevo;
	}
}


void Grafo::mostrar_grafo() {
	Nodo* ptr;
	Aristas* ar;

	ptr = raiz;

	cout << "NODO|LISTA DE ADYACENCIA\n";

	while (ptr != nullptr)
	{
		cout << "   " << ptr->dato << "|";
		if (ptr->adyaciencia != nullptr)
		{
			ar = ptr->adyaciencia;
			while (ar != nullptr)
			{
				cout << " " << ar->vertice->dato;
				ar = ar->siguiente;
			}

		}
		ptr = ptr->siguiente;
		cout << endl;
	}
}