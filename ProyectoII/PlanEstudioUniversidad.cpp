#include "PlanEstudioUniversidad.h"

PlanEstudioUniversidad::PlanEstudioUniversidad()
: raices(nullptr) {
}

void PlanEstudioUniversidad::agregarMateriaPadre( int _codigoMateria, int _uv,
	int _añoPlan, int _periodo, const char* _nombreMateria) {
	materia* padre = new materia(_codigoMateria, _nombreMateria, _uv, _añoPlan, _periodo);

	materia** tmp = new materia * [cantidadRaices + 1];

	for (int i = 0; i < cantidadRaices; i++)
		tmp[i] = raices[i];

	tmp[cantidadRaices] = padre;

	raices = tmp;
	cantidadRaices++;
}

void PlanEstudioUniversidad::agregarMateria(int _codigoPadre, int _codigoMateria, int _uv,
	int _añoPlan, int _periodo, const char* _nombreMateria) {

	materia* nueva = new materia(_codigoMateria, _nombreMateria, _uv, _añoPlan, _periodo);

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

			cout << "Clase agregasa exitosamente!\n";
		}
	}
}

void PlanEstudioUniversidad::imprimir() {
	for (int i = 0; i < cantidadRaices; i++) {
		imprimirRec(raices[i]);
	}
}

bool PlanEstudioUniversidad::estaVacio() {
	return raices == nullptr;
}

materia* PlanEstudioUniversidad::buscarRaiz(int _codigoRaiz) {
	if (raices == nullptr)
		return nullptr;

	for (int i = 0; i < cantidadRaices; i++) {
		if (raices[i]->codigo == _codigoRaiz) {
			return raices[i];
		}
	}

	return nullptr;
}

void PlanEstudioUniversidad::imprimirRec(materia* _raiz) {
	if (_raiz == nullptr)
		return;
	
	cout << "materia { codigo: " << _raiz->codigo << ", uv: " << _raiz->uv << ", nombre: " << _raiz->nombre << " }\n";

	for (int i = 0; i < _raiz->cantidadHijos; i++) {
		imprimirRec(_raiz->hijos[i]);
	}
}
