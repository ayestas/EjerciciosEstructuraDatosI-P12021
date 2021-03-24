#include "Matriculas.h"

Matriculas::Matriculas(int _numCuenta) 
: años(nullptr), numCuenta(_numCuenta) {
}

void Matriculas::agregarMatriculaPorAño(int _codigo, int _nota, int _año, int _periodo) {
	matricula* padre = new matricula(_codigo, _nota, _año, _periodo);
	matricula** tmp = new matricula * [cantidadAños + 1];

	for (int i = 0; i < cantidadAños; i++)
		tmp[i] = años[i];

	tmp[cantidadAños] = padre;

	años = tmp;
	cantidadAños++;
	notas.push_back(_nota);
}

void Matriculas::agregarMatriculaPorPeriodo(int _codigo, int _nota, int _año, int _periodo) {
	matricula* nueva = new matricula(_codigo, _nota, _año, _periodo);

	if (estaVacio()) {
		cout << "No existe!!\n";
		delete nueva;
		return;
	}
	else {
		matricula* padre = buscarAño(_año);

		if (padre == nullptr) {
			cout << "No existe!!\n";
			delete nueva;
			return;
		}
		else {
			//Arreglo de apuntadores + 1
			matricula** tmp = new matricula * [padre->cantidadHijas + 1];

			//respaldo de las direcciones de memoria o hijos ya existentes
			for (int i = 0; i < padre->cantidadHijas; i++) {
				tmp[i] = padre->hijas[i];
			}

			//se agrega la nueva materia como hijo del padre al final
			tmp[padre->cantidadHijas] = nueva;

			//se eliminan los hijos
			if (padre->hijas != nullptr) {
				delete padre->hijas;
			}

			//se asigna el nuevo arreglo actualizado
			padre->hijas = tmp;
			padre->cantidadHijas++;
			notas.push_back(_nota);
		}
	}
}

void Matriculas::imprimir() {
	for (int i = 0; i < cantidadAños; i++)
		imprimirRec(años[i]);
}

matricula* Matriculas::buscarAño(int _año) {
	if (años == nullptr)
		return nullptr;

	for (int i = 0; i < cantidadAños; i++) {
		if (años[i]->año == _año) {
			return años[i];
		}
	}

	return nullptr;
}

int Matriculas::getNumCuenta() {
	return numCuenta;
}

void Matriculas::setNumCuenta(int _numCuenta) {
	this->numCuenta = _numCuenta;
}

double Matriculas::getPromedio() {
	int sumNotas = std::accumulate(notas.begin(), notas.end(), 0);
	double promedio = sumNotas / notas.size();

	return promedio;
}

bool Matriculas::estaVacio() {
	return años == nullptr;
}

void Matriculas::imprimirRec(matricula* _raiz) {
	if (_raiz == nullptr)
		return;

	cout << "materia { codigo: " << _raiz->codigo << ", nota: " << _raiz->nota << ", año: " << _raiz->año
		<< ", periodo: " << _raiz->periodo << " }\n";

	if (_raiz->nota < 60) {
		cout << "Clase Reprobada\n";
	}
	else {
		cout << "Clase Aprobada\n";
	}

	for (int i = 0; i < _raiz->cantidadHijas; i++) {
		imprimirRec(_raiz->hijas[i]);
	}
}


