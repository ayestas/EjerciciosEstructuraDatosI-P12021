#include "PlanEstudio.h"
#include <iostream>

using std::cout;

PlanEstudio::PlanEstudio()
: raiz(nullptr) {
}

void PlanEstudio::agregarMateria(int _codigoPadre, int _codigoMateria, int _uv, const char* _nombreMateria) {
	materia* nueva = new materia(_codigoMateria, _uv, _nombreMateria);

	if (estaVacio()) {
		raiz = nueva;
	}
	else {
		materia* padre = buscarMateria(_codigoPadre);

		if (padre == nullptr) {
			cout << "Clase requisito no existe!\n";
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

			cout << "Clase agregasa exitosamente!\n";
		}
	}
}

void PlanEstudio::eliminarMateria(int _codigoMateria) {
	materia* padre = buscarPadreRec(_codigoMateria, raiz);
	if (padre != nullptr) {

		for (int i = 0; i < padre->cantidadHijos; i++) {

			if (padre->hijos[i]->codigo == _codigoMateria) {

				if (padre->hijos[i]->cantidadHijos > 0) {

					materia** nuevosHijos = new materia * [padre->cantidadHijos - 1 + padre->hijos[i]->cantidadHijos];
					int k = 0;
					for (int j = 0; j < padre->cantidadHijos; j++) {

						if (i != j) {
							nuevosHijos[k] = padre->hijos[j];
							k++;
						}

					}//

					for (int l = 0; l < padre->hijos[i]->cantidadHijos; l++) {
						nuevosHijos[k] = padre->hijos[i]->hijos[l];
						k++;
					}

					padre->cantidadHijos = padre->cantidadHijos - 1 + padre->hijos[i]->cantidadHijos;
					delete padre->hijos;
					padre->hijos = nuevosHijos;
					return;

				}//
				//cuando el nodo que se va a eliminar no tiene hijos
				else {
					materia** nuevosHijos = new materia * [padre->cantidadHijos - 1];
					int k = 0;
					for (int j = 0; j < padre->cantidadHijos; j++) {
						if (i != j) {
							nuevosHijos[k] = padre->hijos[j];
							k++;
						}
					}
					padre->cantidadHijos = padre->cantidadHijos - 1;
					delete padre->hijos;
					padre->hijos = nuevosHijos;
					return;
				}
			}
		}
	}//fin de padre
}

void PlanEstudio::imprimir() {
	imprimirRec(raiz);
}

materia* PlanEstudio::buscarMateria(int _codigoPadre) {
	return buscarMateriasRec(raiz, _codigoPadre);
}

bool PlanEstudio::estaVacio() {
	return raiz == nullptr;
}

materia* PlanEstudio::buscarMateriasRec(materia* _raiz, int _codigoPadre) {
	if (_raiz == nullptr) {
		return nullptr;
	}
	if (_raiz->codigo == _codigoPadre) {
		return _raiz;
	}

	for (int i = 0; i < _raiz->cantidadHijos; i++) {
		materia* tmp = buscarMateriasRec(_raiz->hijos[i], _codigoPadre);

		if (tmp != nullptr) {
			return tmp;
		}
	}

	return nullptr;
}

materia* PlanEstudio::buscarPadreRec(int _codigoHijo, materia* _raiz) {
	if (_raiz->cantidadHijos > 0) {
		for (int i = 0; i < _raiz->cantidadHijos; i++) {
			if (_codigoHijo == _raiz->hijos[i]->codigo) {

				return _raiz;
			}
			else {
				materia* tmp = buscarPadreRec(_codigoHijo, _raiz->hijos[i]);
				if (tmp != nullptr) {
					return tmp;
				}
			}
		}
	}
	return nullptr;
}

void PlanEstudio::imprimirRec(materia* _raiz) {
	if (_raiz == nullptr)
		return;

	cout << "materia { codigo: " << _raiz->codigo << ", uv: " << _raiz->uv << ", nombre: " << _raiz->nombre << " }\n";

	for (int i = 0; i < _raiz->cantidadHijos; i++) {
		imprimirRec(_raiz->hijos[i]);
	}
}
