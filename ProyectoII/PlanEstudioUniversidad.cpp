#include "PlanEstudioUniversidad.h"

PlanEstudioUniversidad::PlanEstudioUniversidad()
: raices(nullptr) {
}

void PlanEstudioUniversidad::agregarMateria(int _codigoPadre, int _codigoMateria, int _uv,
	int _añoPlan, int _periodo, const char* _nombreMateria) {

	
}

void PlanEstudioUniversidad::imprimir()
{
}

materia* PlanEstudioUniversidad::buscarMateria(int _codigoPadre) {
	for (int i = 0; i < cantidadRaices; i++) {
		return buscarMateriasRec(raices[i], _codigoPadre);
	}
}

bool PlanEstudioUniversidad::estaVacio() {
	return raices == nullptr;
}

materia* PlanEstudioUniversidad::buscarMateriasRec(materia* _raices, int _codigoPadre) {
	if (_raices == nullptr)
		return nullptr;
	
	if (_raices->codigo == _codigoPadre)
		return _raices;

	for (int i = 0; i < _raices->cantidadHijos; i++) {
		materia* tmp = buscarMateriasRec(_raices->hijos[i], _codigoPadre);

		if (tmp != nullptr) {
			return tmp;
		}
	}

	return nullptr;
}

materia* PlanEstudioUniversidad::buscarPadreRec(int, materia**)
{
	return nullptr;
}

void PlanEstudioUniversidad::imprimirRec(materia**)
{
}
