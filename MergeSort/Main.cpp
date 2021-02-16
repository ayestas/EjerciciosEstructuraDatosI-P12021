#include <iostream>
#include <conio.h>
using namespace std;
//
void print(int A[], int size) {
	for (int x = 0; x < size; x++) {
		cout << "[ " << A[x] << " ]";
	}
	cout << "\n";
}

//3
void merge(int A[], int left_low, int left_higt, int right_low, int right_high) {
	int lenght = right_high - left_low + 1;
	int* temp = new int[lenght];
	int left = left_low;
	int right = right_low;

	for (int i = 0; i < lenght; ++i) {
		if (left > left_higt) {
			temp[i] = A[right++];
		}
		else if (right > right_high) {
			temp[i] = A[left++];
		}
		else if (A[left] <= A[right]) {
			temp[i] = A[left++];
		}
		else {
			temp[i] = A[right++];
		}
	}

	for (int i = 0; i < lenght; ++i) {
		A[left_low++] = temp[i];
	}
}

//2
void merge_sort(int A[], int low, int high) {
	if (low >= high) {
		return;
	}
	else {
		int medio = (low + high) / 2;
		merge_sort(A, low, medio);
		merge_sort(A, medio + 1, high);
		merge(A, low, medio, medio + 1, high);
	}
}
//1
void merge_sort(int A[], int lenght) {
	merge_sort(A, 0, lenght - 1);
}

int main() {
	int arreglo[] = { 2,6,4,5,3,1 };
	int arr_size = sizeof(arreglo) / sizeof(arreglo[0]);

	cout << "Cantidad de elementos: " << arr_size << endl;
	cout << "Arreglo original\n";
	print(arreglo, arr_size);

	merge_sort(arreglo, arr_size);
	cout << "Arreglo Ordenado\n";
	print(arreglo, arr_size);

	_getch();
}