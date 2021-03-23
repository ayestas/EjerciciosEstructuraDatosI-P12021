#include <iostream>
#include <conio.h>
#include "grafo.h"

// Numero de vertices en el Grafo  
#define V 5  

/* Esta funcion nos permite buscar y por lo tanto encontrar el vertice con menor
distancia entre los que no se han visitado*/
int minimoVertice(int peso[], bool noVistos[])
{
    // El valor minimo sera un INT_MAX porque un vertice puede tener infinito peso,
    // Y min_pos que almacenara la pocion de donde se encuentra ese vector con minima distancia.
    int min = INT_MAX, min_pos;

    for (int v = 0; v < V; v++)
        if (noVistos[v] == false && peso[v] < min)
            min = peso[v], min_pos = v;

    return min_pos;
}

/* La funcion de print nos permite hacer la salida de pantalla de las distancias minimas que nos deja
el arbol recubridor o de distancias minimas.*/
void printMST(int arbolRecubridor[], int grafo[V][V])
{
    int pesoTotal = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << arbolRecubridor[i] << " - " << i << " \t" << grafo[i][arbolRecubridor[i]] << " \n";
        pesoTotal += grafo[i][arbolRecubridor[i]];
    }

    cout << "El Peso final del arbol es de: " << pesoTotal;
}

/*La funcion primMST, a traves del uso del arbol de distancias/pesos minimos encuentra
las distancias mas cortas para llegar a todos los vertices*/
void primMST(int grafo[V][V])
{
    // Aqui se guarda el Arbol Recubridor.  
    int arbolRecubridor[V];

    // Aqui guardamos el peso minimo en cada recorrido por el arbol.  
    int peso[V];

    // Almacena si los vertices se ven representados en el arbol.  
    bool verticesMTS[V];

    // Inicializamos las distancias o pesos del arbol el INT_MAX y
    // establecemos que ningun vertice se ve reflejado en el arbol aun.
    for (int i = 0; i < V; i++)
        peso[i] = INT_MAX, verticesMTS[i] = false;

    /* Esta estructura toma el primer vertice siempre para buscar las demas
    distancias.*/
    peso[0] = 0;
    arbolRecubridor[0] = -1;

    // EL arbol tendra la cantidas V de vertices que es equivalente al numero
    //de vertices de grafo.
    for (int count = 0; count < V - 1; count++)
    {
        /* Buscamos el minimp peso en los vertices no visitados*/
        int u = minimoVertice(peso, verticesMTS);

        /* agregamos dicho vertice a los visitados o que ya estan representados
        en el arbol*/
        verticesMTS[u] = true;

        /* Se actualiza el peso minimo para el vertice*/
        for (int v = 0; v < V; v++)

            // grafo[u][v] es diferente de 0 osea que tiene una distancia.  
            // verticesMTS[v] es falso para los vertices que no estan incluidos en el arbol aun.  
            // Actualiza el peso solo si grafo[u][v] es mas pequenio que el peso[v]  
            if (grafo[u][v] && verticesMTS[v] == false && grafo[u][v] < peso[v])
                arbolRecubridor[v] = u, peso[v] = grafo[u][v];
    }

    // Imprecion del resultado del arbol recubridor.  
    printMST(arbolRecubridor, grafo);
}



int main() {
    Grafo grafo;

    grafo.agregarVertice('A');
    grafo.agregarVertice('B');
    grafo.agregarVertice('C');
    grafo.agregarVertice('D');
    grafo.agregarVertice('E');
    grafo.agregarVertice('F');
    grafo.agregarVertice('G');
    grafo.imprimir();

    grafo.agregarArista('A', 'B', 7);
    grafo.agregarArista('A', 'D', 5);
    grafo.agregarArista('B', 'C', 8);
    grafo.agregarArista('C', 'E', 5);
    grafo.agregarArista('E', 'G', 9);
    grafo.agregarArista('G', 'F', 11);
    grafo.agregarArista('F', 'D', 6);
    grafo.agregarArista('D', 'E', 15);
    grafo.agregarArista('D', 'B', 9);

    grafo.agregarArista('B', 'A', 7);
    grafo.agregarArista('D', 'A', 5);
    grafo.agregarArista('C', 'B', 8);
    grafo.agregarArista('E', 'C', 5);
    grafo.agregarArista('G', 'E', 9);
    grafo.agregarArista('F', 'G', 11);
    grafo.agregarArista('D', 'F', 6);
    grafo.agregarArista('E', 'D', 15);
    grafo.agregarArista('B', 'D', 9);

    grafo.imprimir();

    grafo.imprimirArbol(grafo.prim());


    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);
    _getch();
}