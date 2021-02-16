#include <iostream>
#include <conio.h>
#include "Locker.h"

int main() {
    Locker l(10);
    l.arrayLockers[0] = 1;
    l.arrayLockers[1] = 10;
    l.arrayLockers[2] = 3;
    l.arrayLockers[3] = 4;
    l.arrayLockers[4] = 8;
    l.arrayLockers[5] = 91;
    l.arrayLockers[6] = 67;
    l.arrayLockers[7] = 9;
    l.arrayLockers[8] = 11;
    l.arrayLockers[9] = 22;

    l.imprimir();
    std::cout << std::endl;

    std::cout << "Ingrese un valor: ";
    int valor;
    std::cin >> valor;

    std::cout << std::endl;


    if (l.linearSearch(valor) > 0)
    {
        std::cout << "La posicion del valor es " << l.linearSearch(valor) << std::endl;
    }
    else {
        std::cout << "No se encuentra el valor en el arreglo." << std::endl;
    }

    _getch();
}
