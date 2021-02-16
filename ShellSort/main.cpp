#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <chrono>

using namespace std;

/*Funcion de ayuda para std::generate que llenara nuestro vector de numeros*/
int randomNum()
{
	return 1 + (rand() % 200);
}

/*Funcion para ordenenar con shell sort*/
vector<int> shellSort(vector<int> vec)
{
	//Se inicia el sorteo con una distancia de la mitad del vector entre intercambios
	for (int gap = (vec.size() / 2); gap > 0; gap /= 2)
	{
		/*Seguira ordenando mientras quede espacio entre los elementos, una vez ya sea solo de un espacio hara un insertion sort normal, pero casi ordenado, lo cual lo hace eficiente*/
		for (int i = gap; i < vec.size(); i++)
		{
			//Se guarda el elemento en la posicion i, y se hace un hueco en esa posicion i
			int temp = vec.at(i);

			/*Se intercambia los elementos previamente ordenados(con la distancia entre los interacambios) hasta que la posicion correcta de vec[i] se encuentre*/
			/* i  > j*/
			int j;
			for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
			{
				vec[j] = vec[j - gap];
			}

			//El temp (el numero original de vec[i] se ingresa en su posicion correcta, complentando el intercambio
			vec[j] = temp;
		}
	}
	return vec;
}

/* Funcion para imprimir el vector*/
void printVec(vector<int> vec)
{
	cout << endl << "Vector >-------------------->" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "Vector[" << i << "]\t = " << "[ " << vec[i] << " ]" << endl;
	}
}

int main()
{
	auto start = std::chrono::steady_clock::now();
	int size = 1000;

	/*vector<int> vec(size);
	generate(vec.begin(), vec.end(), randomNum);
	printVec(vec);
	cout << "Aprete cualquier tecla para hacer el ordenamiento" << endl;
	_getch();*/
	//
	//vec = shellSort(vec);
	int total = 0;
	while (true)
	{

		auto last = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(last - start).count() >= 1)
		{
			total += 1;
			cout << "Total: " << total << endl;
			cout << "Tick: " << std::chrono::duration_cast<std::chrono::seconds>(last - start).count() << endl;
			start = chrono::steady_clock::now();
		}
	}
	auto last = std::chrono::steady_clock::now();
	auto interval = last - start;


	/*printVec(vec);
	cout << "Time in secs for printing + algo: " << chrono::duration_cast<chrono::seconds>(interval).count() << "secs" << endl;
	_getch();*/
}