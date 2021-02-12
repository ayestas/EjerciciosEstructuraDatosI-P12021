#include <iostream>

using namespace std;

void MostrarArreglo(const int[], int);

int BusquedaBinaria(const int[], int, int);

void OrdenarArreglo(int[], int); 

void Intercambiar(int&, int&);

int main() {

    int clave = 0;
    const int tamano = 15;

    int arreglo[tamano] = { 25,17,13,16,41,32,12,115,95,84,54,63,78,21,10 };
    OrdenarArreglo(arreglo, tamano);

    cout << "Elementos del arreglo: " << endl;
    MostrarArreglo(arreglo, tamano);

    cout << "\nIndique un valor a buscar y se le devolvera el indice: ";
    cin >> clave;
    cout << "\nSu valor se encuentra en el arreglo en la posicion: [" << BusquedaBinaria(arreglo, tamano, clave) << "]" << endl;
    cout << "Fin del programa :)" << endl;

    return 0;
}

int BusquedaBinaria(const int arreglo[], int tamano, int clave) {
    int derecha = tamano - 1;
    int izquierda = 0;
    int centro;

    while (izquierda <= derecha)
    {
        centro = (derecha + izquierda) / 2;
        if (arreglo[centro] == clave)
            return centro;
        else
            if (clave < arreglo[centro])
                derecha = centro - 1;
            else
                izquierda = centro + 1;
    }
    return -1;
}

void MostrarArreglo(const int arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++)
        cout << "[" << i << "]=" << arreglo[i] << endl;
}

void OrdenarArreglo(int arreglo[], int tamano) {
    for (int i = 0; i < tamano - 1; i++)
        for (int j = 0; j < tamano - 1; j++)
            if (arreglo[j] > arreglo[j + 1])
                Intercambiar(arreglo[j], arreglo[j + 1]);
}

void Intercambiar(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
}