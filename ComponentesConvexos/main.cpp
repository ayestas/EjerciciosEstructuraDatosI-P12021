#include <iostream>
#include <list>
#include <stack>

using std::cout;
using std::endl;
using std::list;
using std::stack;

class Grafo {
    int vertices;
    list<int>* adyacentes;
    void Orden(int vertice, bool visitado[], stack<int>& Stack);
    //ALGORITMO DE BUSQUEDA
    void CFC(int vertice, bool visitado[]);

public:
    Grafo(int cantVertices);
    void agregarArista(int vertice, int verticeSiguiente);
    //Imprimir Componente Fuertemente Conectado
    void imprimirCFC();
    //Cambia a dirección contraria a la aristas
    Grafo trasponer();
};

Grafo::Grafo(int cantVertices) {
    this->vertices = cantVertices;
    adyacentes = new list<int>[cantVertices];
}

//CFC
void Grafo::CFC(int vertice, bool visitado[]) {
    visitado[vertice] = true;
    cout << vertice << " ";

    list<int>::iterator i;
    for (i = adyacentes[vertice].begin(); i != adyacentes[vertice].end(); ++i)
        if (!visitado[*i])
            CFC(*i, visitado);
}

// Transponer
Grafo Grafo::trasponer() {
    Grafo g(vertices);
    //s -> vertice
    for (int s = 0; s < vertices; s++) {
        list<int>::iterator i;
        for (i = adyacentes[s].begin(); i != adyacentes[s].end(); ++i) {
            g.adyacentes[*i].push_back(s);
        }
    }
    return g;
}

//Agergar arista al grafo
void Grafo::agregarArista(int vertice, int verticeSiguiente) {
    adyacentes[vertice].push_back(verticeSiguiente);
}

void Grafo::Orden(int vertice, bool visitado[], stack<int>& Stack) {
    visitado[vertice] = true;

    list<int>::iterator i;
    for (i = adyacentes[vertice].begin(); i != adyacentes[vertice].end(); ++i)
        if (!visitado[*i])
            Orden(*i, visitado, Stack);

    Stack.push(vertice);
}

// Print strongly connected component
void Grafo::imprimirCFC() {
    stack<int> Stack;

    bool* visitado = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visitado[i] = false;

    for (int i = 0; i < vertices; i++)
        if (visitado[i] == false)
            Orden(i, visitado, Stack);

    Grafo g = trasponer();

    for (int i = 0; i < vertices; i++)
        visitado[i] = false;

    while (Stack.empty() == false) {
        int s = Stack.top();
        Stack.pop();

        if (visitado[s] == false) {
            g.CFC(s, visitado);
            cout << endl;
        }
    }
}

int main() {
    Grafo g(4);
    g.agregarArista(0, 1);
    g.agregarArista(0, 3);
    g.agregarArista(1, 2);
    g.agregarArista(2, 3);
    g.agregarArista(2, 0);

    cout << "Componentes Fuertemente Conectados:\n";
    g.imprimirCFC();
}