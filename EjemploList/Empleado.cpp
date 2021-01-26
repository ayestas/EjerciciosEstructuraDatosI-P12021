#include "Empleado.h"
#include <iostream>

using namespace std;

Empleado::Empleado()
	: codigoEmpleado(0), nombreEmpleado("nd"), salarioEmpleado(0) {


}

Empleado::Empleado(int _codigo, std::string _nombre, float _salario) 
	: codigoEmpleado(_codigo), nombreEmpleado(_nombre), salarioEmpleado(_salario) {
}

//void Empleado::ImprimirEmpleado() {
//	cout << "Empleado { codigo: " << codigoEmpleado << ", nombre: " << nombreEmpleado << ", salario: " << salarioEmpleado << " }\n";
//}

std::ostream& operator<<(std::ostream& cout, const Empleado& a) {
	cout << "Empleado { codigo: " << a.codigoEmpleado << ", nombre: " << a.nombreEmpleado << ", salario: " << a.salarioEmpleado << " }\n";

	return cout;
}
