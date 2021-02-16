#include <bits/stdc++.h>


using namespace std;

//int arr[] = {15, 120, 53, 36, 167, 81, 75, 32, 9, 60};
void radix_sort(int arr[], int n) {


    //Paso 1.Encontar el elemento maximo
    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        maximum = max(maximum, arr[i]);
    }


    //Paso 2:Contar el numero de digitos del numero maximo
    int digits = 0;

    while (maximum > 0) {
        digits++;
        maximum /= 10;
    }


    // Paso 3,4,5:Organiza los números sobre la base de dígitos 
    for (int i = 0; i < digits; i++) {


        //Unidades / decenas / centenas: se utilizan para determinar qué dígito 
        int power = pow(10, i);

        //Contiene la matriz actualizada 
        int new_array[n];


        // Counting Sort Array -necesaria para organizar digitos [0-9]
        int count[10];


        //Inicializando el Count Array
        memset(count, 0, sizeof(count));


        //Cálculo de la frecuencia de dígitos 
        for (int j = 0; j < n; j++) {


            //El dígito en consideración en esta iteración 
            int num = (arr[j] / power) % 10;

            count[num]++;
        }


        //Frecuencia acumulativa de la matriz de conteo 
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }


        //Designar nuevas posiciones en la matriz actualizada
        for (int j = n - 1; j >= 0; j--) {

            //El dígito en consideración en esta iteración 
            int num = (arr[j] / power) % 10;

            new_array[count[num] - 1] = arr[j];
            count[num]--;
        }


        //Actualización de la matriz original usando un nuevo arrreglo
        for (int j = 0; j < n; j++)
            arr[j] = new_array[j];

    }

    //Impirmir ya el resultado
    for (int j = 0; j < n; j++)
        cout << arr[j] << " ";

    cout << endl;
}


int main() {


    int arr[] = { 15, 120, 53, 36, 167, 81, 75, 32, 9, 60 };



    //tamaño del arreglo
    int n = sizeof(arr) / sizeof(n);

    // Function call for the Radix Sort Algorithm 
    radix_sort(arr, n);

    return 1;
}