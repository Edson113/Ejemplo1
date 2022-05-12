//hola
#include <iostream>
#include <string>

using namespace std;
struct Person {
	string name;
	int age;
	double height;
};
struct Nodo {
	Person dato;
	Nodo* ant;
	Nodo* sgte;
};
void insertarFinal(Nodo*&, Person);
void listar(Nodo*);
int main(void) {
	Nodo* listaDoble = NULL;
	int cant;
	Person valor;
	cout << "LISTA DOBLE" << endl;
	do {
		cout << "Cantidad de personas a ingresar: "; cin >> cant;
	} while (cant <= 0);
	for (int i = 0; i < cant; i++) {
		cout << "\n\nDATOS PERSONA [" << i + 1 << "]" << endl;
		cout << "\nNombre: "; cin.ignore();
		getline(cin, valor.name);
		cout << "Edad: ";
		cin >> valor.age;
		cout << "Estatura: ";
		cin >> valor.height; cout << endl;

		insertarFinal(listaDoble, valor);
	}
	cout << "\n\n\nElementos de la lista: " << endl;
	listar(listaDoble);
	return 0;
}
void insertarFinal(Nodo*& listaDoble, Person valor)
{
	Nodo* nuevoNodo, * ultimo;
	nuevoNodo = new Nodo;
	nuevoNodo->dato = valor;
	nuevoNodo->sgte = NULL;
	if (listaDoble == NULL) {
		nuevoNodo->ant = NULL;
		listaDoble = nuevoNodo;
	}
	else {
		ultimo = listaDoble;
		while (ultimo->sgte != NULL) {
			ultimo = ultimo->sgte;
		}
		ultimo->sgte = nuevoNodo;
		nuevoNodo->ant = ultimo;
	}
}
void listar(Nodo* listaDoble) {
	Nodo* ultimo = listaDoble, * actual;
	while (ultimo->sgte != NULL) {
		ultimo = ultimo->sgte;
	}
	actual = ultimo;
	while (actual != NULL) {
		cout << actual->dato.name << endl;
		cout << actual->dato.age << endl;
		cout << actual->dato.height << endl;
		cout << endl << endl;
		actual = actual->ant;
	}
}