#include "PlanEstudioUniversidad.h"
#include <iostream>
#include <fstream>
#include <string>

PlanEstudioUniversidad::PlanEstudioUniversidad() {
	
}

void PlanEstudioUniversidad::agregarPlanEstudio(int _codigo, const char* _nombre, int _bloques) {
	string filename = std::to_string(_codigo) + "_plan.bin";
	ofstream planFile(filename, ios::out | ios::app | ios::binary);
	if (!planFile) {
		cout << "Error al intentar abrir el archivo .bin\n";
		return;
	}
	archivo nuevo;

	nuevo.codigo = _codigo;
	nuevo.nombre = new char[strlen(_nombre)];
	strcpy_s(nuevo.nombre, strlen(_nombre) + 1, _nombre);
	nuevo.bloques = _bloques;
	
	nuevo.totalClases = 0;
	nuevo.totalUV = 0;

	codigos.push_back(_codigo);

	agregarMateriaPadre(_bloques, _codigo);

	planFile.write(reinterpret_cast<const char*>(&nuevo), sizeof(archivo));

	planFile.close();

}

void PlanEstudioUniversidad::agregarMateriaPadre(int bloques, int _codigoPlan) {
	Materias* nuevoArbol = new Materias(_codigoPlan);

	for (int i = 0; i < bloques; i++) {
		int _codigoMateria = 0, _uv = 0, _añoPlan = 0, _periodo = 0;
		string nombre = "";
		const char* _nombre = new char[40];

		cout << "\nIngrese el codigo de la clase: ";
		cin >> _codigoMateria;
		cout << "\nIngrese el nombre de la clase: ";
		cin >> nombre;
		cout << "\nIngrese las unidades valorativas: ";
		cin >> _uv;
		cout << "\nIngrese el año de ingreso: ";
		cin >> _añoPlan;
		cout << "\nIngrese el periodo de ingreso: ";
		cin >> _periodo;

		_nombre = nombre.c_str();

		nuevoArbol->agregarMateriaPadre(_codigoMateria, _uv, _añoPlan, _periodo, _nombre, 0);

		cout << "\nBLOQUE AGREGADO CON EXITO!!!\n";
	}

	VecClases.push_back(nuevoArbol);
}

void PlanEstudioUniversidad::agregarMateria(int _codigoPlan, int _codigoRaiz) {
	for (int i = 0; i < VecClases.size(); i++) {
		if (VecClases[i]->getCodigoPlan() == _codigoPlan) {
			int _codigoMateria = 0, _uv = 0, _añoPlan = 0, _periodo = 0, _requisito = 0;
			string nombre = "";
			const char* _nombre = new char[40];

			cout << "\nIngrese el codigo de la clase: ";
			cin >> _codigoMateria;
			cout << "\nIngrese el nombre de la clase: ";
			cin >> nombre;
			cout << "\nIngrese las unidades valorativas: ";
			cin >> _uv;
			cout << "\nIngrese el año de ingreso: ";
			cin >> _añoPlan;
			cout << "\nIngrese el periodo de ingreso: ";
			cin >> _periodo;
			cout << "\nIngrese el codigo de clase requisito: ";
			cin >> _requisito;

			_nombre = nombre.c_str();

			VecClases[i]->agregarMateria(_codigoRaiz, _codigoMateria, _uv, _añoPlan, _periodo, _nombre, _requisito);

			cout << "\nCLASE AGREGADA CON EXITO!!!\n";
		}
	}
}

void PlanEstudioUniversidad::consultarPlanEstudio() {
	for (int i = 0; i < codigos.size(); i++) {
		string filename = std::to_string(codigos[i]) + "_plan.bin";

		ifstream planFile(filename, ios::in | ios::binary);
		if (!planFile)
			cout << "Error al intentar abrir el archivo .bin\n";

		archivo actual;

		planFile.seekg(0, ios::beg);
		planFile.read(reinterpret_cast<char*>(&actual), sizeof(archivo));

		while (!planFile.eof()) {
			cout << "Plan Estudio { codigo: " << actual.codigo << ", nombre: " << actual.nombre
				<< ", cantidad de clases: " << actual.totalClases << ", total de UV: " << actual.totalUV
				<< ", cantidad de bloques: " << actual.bloques << " }\n";
			planFile.read(reinterpret_cast<char*>(&actual), sizeof(archivo));
		}

		planFile.close();
	}
}

void PlanEstudioUniversidad::imprimirClases(int _codigoPlan) {
	for (int i = 0; i < VecClases.size(); i++) {
		if (VecClases[i]->getCodigoPlan() == _codigoPlan) {
			VecClases[i]->imprimir();
		}
	}
}

bool PlanEstudioUniversidad::BuscarPlanEstudio(int _codigo) {
	if (std::find(codigos.begin(), codigos.end(), _codigo) != codigos.end()) {
		cout << "\nEXISTE\n";
		return true;
	}
	else {
		cout << "\nNO EXISTE\n";
		return false;
	}

}
