#include "PlanEstudioUniversidad.h"
#include <iostream>
#include <fstream>
#include <string>

PlanEstudioUniversidad::PlanEstudioUniversidad() {
	
}

void PlanEstudioUniversidad::agregarPlanEstudio(int _codigo, const char* _nombre, int _bloques, int _clases) {
	string filename = std::to_string(_codigo) + "_plan.bin";
	ofstream planFile(filename, ios::out | ios::app | ios::binary);
	if (!planFile) {
		cout << "Error al intentar abrir el archivo .bin\n";
		return;
	}
	archivo nuevo;
	clases clase;
	int UVs = 0;

	nuevo.codigo = _codigo;
	nuevo.nombre = new char[strlen(_nombre)];
	strcpy_s(nuevo.nombre, strlen(_nombre) + 1, _nombre);
	nuevo.bloques = _bloques;
	nuevo.totalClases = _clases;
	nuevo.totalUV = UVs;

	Materias* nuevoArbol = new Materias(_codigo);

	planFile.write(reinterpret_cast<const char*>(&nuevo), sizeof(archivo));

	for (int i = 0; i < _bloques; i++) {
		int _codigoMateria = 0, _uvMateria = 0, _añoPlanMateria = 0, _periodoMateria = 0;
		string nombreMateria = "";
		const char* _nombreMateria = new char[40];

		cout << "\n* INGRESO  BLOQUES *";
		cout << "\nIngrese el codigo de la clase: ";
		cin >> _codigoMateria;
		cout << "Ingrese el nombre de la clase: ";
		cin >> nombreMateria;
		cout << "Ingrese las unidades valorativas: ";
		cin >> _uvMateria;
		cout << "Ingrese el año de ingreso: ";
		cin >> _añoPlanMateria;
		cout << "Ingrese el periodo de ingreso: ";
		cin >> _periodoMateria;

		_nombreMateria = nombreMateria.c_str();
		UVs += _uvMateria;

		clase.codigo = _codigoMateria;
		clase.nombre = new char[strlen(_nombreMateria)];
		strcpy_s(clase.nombre, strlen(_nombreMateria) + 1, _nombreMateria);
		clase.uv = _uvMateria;
		clase.añoPlan = _añoPlanMateria;
		clase.periodo = _periodoMateria;
		clase.requisito = 0;

		nuevoArbol->agregarMateriaPadre(_codigoMateria, _uvMateria, _añoPlanMateria, _periodoMateria, _nombreMateria, 0);
		planFile.write(reinterpret_cast<const char*>(&clase), sizeof(clases));

		cout << "\nBLOQUE AGREGADO CON EXITO!!!\n";
	}

	for (int i = 0; i < _clases; i++) {
		int  _codigoPadre = 0, _codigoMateria = 0, _uvMateria = 0, _añoPlanMateria = 0, _periodoMateria = 0, _requisitoMateria = 0;
		string nombreMateria = "";
		const char* _nombreMateria = new char[40];

		cout << "\n* INGRESO CLASES *";
		cout << "\nIngrese el codigo del bloque donde ubicar la clase: ";
		cin >> _codigoPadre;
		cout << "Ingrese el codigo de la clase: ";
		cin >> _codigoMateria;
		cout << "Ingrese el nombre de la clase: ";
		cin >> nombreMateria;
		cout << "Ingrese las unidades valorativas: ";
		cin >> _uvMateria;
		cout << "Ingrese el año de ingreso: ";
		cin >> _añoPlanMateria;
		cout << "Ingrese el periodo de ingreso: ";
		cin >> _periodoMateria;
		cout << "Ingrese el codigo de clase requisito: ";
		cin >> _requisitoMateria;

		_nombreMateria = nombreMateria.c_str();
		UVs += _uvMateria;

		clase.codigo = _codigoMateria;
		clase.nombre = new char[strlen(_nombreMateria)];
		strcpy_s(clase.nombre, strlen(_nombreMateria) + 1, _nombreMateria);
		clase.uv = _uvMateria;
		clase.añoPlan = _añoPlanMateria;
		clase.periodo = _periodoMateria;
		clase.requisito = 0;

		nuevoArbol->agregarMateria(_codigoPadre, _codigoMateria, _uvMateria, _añoPlanMateria, _periodoMateria, _nombreMateria, _requisitoMateria);
		planFile.write(reinterpret_cast<const char*>(&clase), sizeof(clases));

		cout << "\nCLASE AGREGADA CON EXITO!!!\n";
	}

	VecClases.push_back(nuevoArbol);
	codigos.push_back(_codigo);

	planFile.close();

}

void PlanEstudioUniversidad::consultarPlanEstudio(int _codigoPlan) {
	string filename = std::to_string(_codigoPlan) + "_plan.bin";
	ifstream planFile(filename, ios::in | ios::binary);
	if (!planFile)
		cout << "Error al intentar abrir el archivo .bin\n";

	archivo actual;
	clases clase;

	planFile.seekg(0, ios::beg);

	planFile.read(reinterpret_cast<char*>(&actual), sizeof(archivo));

	while (!planFile.eof()) {
		cout << "Plan Estudio { codigo: " << actual.codigo << ", nombre: " << actual.nombre
			<< ", cantidad de clases: " << actual.totalClases << ", total de UV: " << actual.totalUV
			<< ", cantidad de bloques: " << actual.bloques << " }\n\n";

		planFile.read(reinterpret_cast<char*>(&clase), sizeof(clases));

		cout << "materia { codigo: " << clase.codigo << ", nombre: " << clase.nombre
			<< ", UVs: " << clase.uv << ", año: " << clase.añoPlan << ", periodo: "
			<< clase.periodo << ", requisito: " << clase.requisito << " }\n";
	}

	planFile.close();

	cout << "\n";
	imprimirClases(_codigoPlan);
}

void PlanEstudioUniversidad::imprimirClases(int _codigoPlan) {
	for (int i = 0; i < VecClases.size(); i++) {
		if (VecClases[i]->getCodigoPlan() == _codigoPlan) {
			VecClases[i]->imprimir();
		}
	}
}

void PlanEstudioUniversidad::ingresarAlumno(int _numero, const char* _nombre, int _indice, int _clasesAprob, int _codigoPlan) {
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

	Matriculas* matricula = new Matriculas(_numero);
	VecMatriculadas.push_back(matricula);

	alumnoFile.write(reinterpret_cast<const char*>(&nuevo), sizeof(alumnos));

	alumnoFile.close();
}

void PlanEstudioUniversidad::ingresarMatricula() {
	int _numCuenta = 0, cantClases = 0, codigoMateria = 0, _nota = 0, _año = 0, _periodo = 0;

	cout << "\n* MATRICULA DE CLASES *\nIngrese su numero de cuenta: ";
	cin >> _numCuenta;

	if (BuscarAlumno(_numCuenta)) {
		cout << "\n* CLASES DISPONIBLES *\n";
		imprimirClases(getCodigoPlan(_numCuenta));

		cout << "\n\nIngrese la cantidad de clases a matricular: ";
		cin >> cantClases;

		for (int i = 0; i < cantClases; i++) {
			cout << "\nIngrese codigo de la materia a matricular: ";
			cin >> codigoMateria;
			cout << "Ingrese la nota de la clase: ";
			cin >> _nota;
			cout << "Ingrese el año de matricula: ";
			cin >> _año;
			cout << "Ingrese el periodo de matricula: ";
			cin >> _periodo;



			if (!BuscarAñoMatriculado(_año)) {
				for (int i = 0; i < VecMatriculadas.size(); i++) {
					if (VecMatriculadas[i]->getNumCuenta() == _numCuenta) {
						añosMatriculados.push_back(_año);
						VecMatriculadas[i]->agregarMatriculaPorAño(codigoMateria, _nota, _año, _periodo);
					}
				}
			}
			else {
				for (int i = 0; i < VecMatriculadas.size(); i++) {
					if (VecMatriculadas[i]->getNumCuenta() == _numCuenta) {
						VecMatriculadas[i]->agregarMatriculaPorPeriodo(codigoMateria, _nota, _año, _periodo);
					}
				}
			}
		}
	}
}

void PlanEstudioUniversidad::imprimirInfoAcademica(int _numCuenta) {
	cout << "\n\n* PROMEDIO ACADEMICO *\n";
	for (int i = 0; i < VecMatriculadas.size(); i++) {
		if (VecMatriculadas[i]->getNumCuenta() == _numCuenta) {
			cout << "Promedio: " << VecMatriculadas[i]->getPromedio();
		}
	}

	cout << "\n\n* HISTORIAL ACADEMICO *\n";
	
	for (int i = 0; i < VecMatriculadas.size(); i++) {
		if (VecMatriculadas[i]->getNumCuenta() == _numCuenta) {
			VecMatriculadas[i]->imprimir();
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

bool PlanEstudioUniversidad::BuscarAñoMatriculado(int _año) {
	if (std::find(añosMatriculados.begin(), añosMatriculados.end(), _año) != añosMatriculados.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool PlanEstudioUniversidad::BuscarAlumno(int _numero) {
	if (std::find(numCuentas.begin(), numCuentas.end(), _numero) != numCuentas.end()) {
		cout << "\nEXISTE\n";
		return true;
	}
	else {
		cout << "\nNO EXISTE\n";
		return false;
	}
}

int PlanEstudioUniversidad::getCodigoPlan(int _numCuenta) {
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
