#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int>  ordenamientoBurbuja(vector<int> _datos) {
	for (int i = 0; i < _datos.size(); i++)
	{
		for (int j = 0; j < (_datos.size() - 1) - i; j++)
		{
			if (_datos[j] > _datos[j + 1])
			{
				int aux = _datos[j];
				_datos[j] = _datos[j + 1];
				_datos[j + 1] = aux;
			}
		}
	}

	return _datos;
}

vector<int> ordenamientoSeleccion(vector<int> _datos) {
	for (int i = 0; i < _datos.size(); i++)
	{
		for (int j = i; j < _datos.size(); j++)
		{
			if (_datos[i] > _datos[j])
			{
				int aux = _datos[j];
				_datos[j] = _datos[i];
				_datos[i] = aux;
			}
		}
	}

	return _datos;
}

void imprimirDatos(vector<int> _datos) {
	cout << "* * * L i s t a  d e  D a t o s * * *\n";

	for (int i = 0; i < _datos.size(); i++) {
		cout << "[ " << _datos[i] << " ] ";
	}
	cout << "\n\n";
}


int main() {
	vector<int> numeros{ 3,9,4,5,6,56,78,35,56,72,67,90 };

	cout << "Datos sin ordenar: " << endl;
	imprimirDatos(numeros);


	/*cout << "Datos Ordenados con Ordenamiento Burbuja: " << endl;
	numeros = ordenamientoBurbuja(numeros);
	imprimirDatos(numeros);*/


	cout << "Datos Ordenados con Ordenamiento De Seleccion: " << endl;
	numeros = ordenamientoSeleccion(numeros);
	imprimirDatos(numeros);

	return 1;
}