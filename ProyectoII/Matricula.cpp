#include "Matricula.h"
#include <iostream>
#include <fstream>
#include <string>

Matricula::Matricula()
: raices(nullptr) {
}

void Matricula::ingresarAlumno() {
	int _numero = 0, _codigoPlan = 0, _indice = 0, _clasesAprob = 0;
	string nombre = "";
	const char* _nombre = new char[20];

	cout << "\n* INGRESO DE ALUMNOS *";
	cout << "\nIngrese el numero de cuenta: ";
	cin >> _numero;
	cout << "Ingrese el nombre del alumno: ";
	cin >> nombre;
	cout << "Ingrese el indice del alumno: ";
	cin >> _indice;
	cout << "Ingrese el periodo de ingreso: ";
	cin >> _clasesAprob;
	cout << "Ingrese el codigo del plan de estudio: ";
	cin >> _codigoPlan;

	_nombre = nombre.c_str();

	if (planes->BuscarPlanEstudio(_codigoPlan)) {

		string filename = std::to_string(_numero) + "_alumno.bin";
		ofstream alumnoFile(filename, ios::out | ios::app | ios::binary);
		if (!alumnoFile) {
			cout << "Error al intentar abrir el archivo .bin\n";
			return;
		}

		numCuentas.push_back(_numero);
		alumnos nuevo;

		nuevo.numero = _numero;
		nuevo.nombre = new char[strlen(_nombre)];
		strcpy_s(nuevo.nombre, strlen(_nombre) + 1, _nombre);
		nuevo.codigoPlan = _codigoPlan;
		nuevo.indice = _indice;
		nuevo.clasesAprob = _clasesAprob;

		alumnoFile.write(reinterpret_cast<const char*>(&nuevo), sizeof(alumnos));

		alumnoFile.close();
	}
	else {
		cout << "El codigo del plan que ingreso no existe!!\n";
		return;
	}
	
}

void Matricula::ingresarMatricula() {
	int _numCuenta = 0;

	cout << "\n* MATRICULA DE CLASES *\nIngrese su numero de cuenta: ";
	cin >> _numCuenta;

	if (existeAlumno(_numCuenta)) {
		materias = planes->getPlan(getCodigoPlan(_numCuenta));

		cout << "\n* CLASES DISPONIBLES *\n";
		

	}
}

bool Matricula::existeAlumno(int _numero) {
	if (std::find(numCuentas.begin(), numCuentas.end(), _numero) != numCuentas.end()) {
		cout << "\nEXISTE\n";
		return true;
	}
	else {
		cout << "\nNO EXISTE\n";
		return false;
	}
}

int Matricula::getCodigoPlan(int _numCuenta) {
	string filename = std::to_string(_numCuenta) + "_alumno.bin";
	ifstream alumnoFile(filename, ios::in, ios::binary);
	if (!alumnoFile)
		return -1;

	alumnos alumno;
	alumnoFile.seekg(0, ios::beg);

	alumnoFile.read(reinterpret_cast<char*>(&alumno), sizeof(alumnos));

	while (!alumnoFile.eof()) {
		if (_numCuenta == alumno.numero) {
			alumnoFile.close();
			return alumno.codigoPlan;
		}
		alumnoFile.read(reinterpret_cast<char*>(&alumno), sizeof(alumnos));
	}

	return -1;
}

