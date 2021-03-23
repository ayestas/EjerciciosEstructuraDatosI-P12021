#include "Materias.h"

Materias::Materias(int _codigoPlan) 
: raices(nullptr), codigoPlan(_codigoPlan) {
}

void Materias::agregarMateriaPadre(int _codigoMateria, int _uv, int _añoPlan, 
	int _periodo, const char* _nombreMateria, int _requisito) {

	materia* padre = new materia(_codigoMateria, _uv, _añoPlan, _periodo, _nombreMateria, _requisito);
	materia** tmp = new materia * [cantidadRaices + 1];

	for (int i = 0; i < cantidadRaices; i++)
		tmp[i] = raices[i];

	tmp[cantidadRaices] = padre;

	raices = tmp;
	cantidadRaices++;
}

void Materias::agregarMateria(int _codigoPadre, int _codigoMateria, int _uv,
	int _añoPlan, int _periodo, const char* _nombreMateria, int _requisito) {

	materia* nueva = new materia(_codigoMateria, _uv, _añoPlan, _periodo, _nombreMateria, _requisito);

	if (estaVacio()) {
		cout << "Clase requisito no existe!\n";
		delete nueva;
		return;
	}
	else {
		materia* padre = buscarRaiz(_codigoPadre);

		if (padre == nullptr) {
			cout << "Clase requisito NO existe!\n";
			delete nueva;
			return;
		} 
		else {

			//Arreglo de apuntadores + 1
			materia** tmp = new materia * [padre->cantidadHijos + 1];

			//respaldo de las direcciones de memoria o hijos ya existentes
			for (int i = 0; i < padre->cantidadHijos; i++) {
				tmp[i] = padre->hijos[i];
			}

			//se agrega la nueva materia como hijo del padre al final
			tmp[padre->cantidadHijos] = nueva;

			//se eliminan los hijos
			if (padre->hijos != nullptr) {
				delete padre->hijos;
			}

			//se asigna el nuevo arreglo actualizado
			padre->hijos = tmp;
			padre->cantidadHijos++;

			cout << "Clase agregada exitosamente!\n";
		}
	}
}

void Materias::imprimir() {
	for (int i = 0; i < cantidadRaices; i++)
		imprimirRec(raices[i]);
}

materia* Materias::buscarRaiz(int _codigoRaiz) {
	if (raices == nullptr)
		return nullptr;

	for (int i = 0; i < cantidadRaices; i++) {
		if (raices[i]->codigo == _codigoRaiz) {
			return raices[i];
		}
	}

	return nullptr;
}

int Materias::getCodigoPlan() {
	return this->codigoPlan;
}

void Materias::setCodigoPlan(int _codigo) {
	this->codigoPlan = _codigo;
}

materia** Materias::getRaices() {
	return this->raices;
}

bool Materias::estaVacio() {
	return raices == nullptr;
}

void Materias::imprimirRec(materia* _raiz) {
	if (_raiz == nullptr)
		return;

	cout << "materia { codigo: " << _raiz->codigo << ", uv: " << _raiz->uv << ", año: " << _raiz->añoPlan 
		<< ", periodo: " << _raiz->periodo <<", nombre: " << _raiz->nombre << ", codigo requisito: " 
		<< _raiz->requisito  << " }\n";

	for (int i = 0; i < _raiz->cantidadHijos; i++) {
		imprimirRec(_raiz->hijos[i]);
	}
}
