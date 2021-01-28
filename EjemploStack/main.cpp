#include <iostream>
#include <conio.h>
#include "Stack.h"

using namespace std;

int main() {
	Stack<string> st;

	st.push("Juan");
	st.push("Bernardo");
	st.push("Daniel");
	st.push("Jairo");
	st.push("Leonardo");
	st.print();

	st.pop();
	st.pop();

	cout << "\n____________________________\n";

	st.print();

	cout << "\n____________________________\n";

	cout << "Tope de la Pila: " << st.peek() << "\n";

	cout << "\n____________________________\n";

	st.push("Marcelo");
	st.push("Luis");
	st.push("Oscar");
	st.push("Mario");
	st.push("Victor");
	st.push("Hector");
	st.push("Karol");


	//no tendria que insertar a pedro por el tamaño predeterminado
	st.push("Pedro");
	st.print();

	_getch();
}