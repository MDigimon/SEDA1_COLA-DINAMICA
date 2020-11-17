#include <iostream>
#include <stdlib.h>


using namespace std;

class Nodo{
	public:
		int valor;
		Nodo* next;
}

int vacia(Nodo* frente){
	if(frente == NULL){
		return 1;
	}
	return 0;
}

void agregar(Nodo *&frente, Nodo *&fin, int n){
	Nodo *nuevo = new Nodo();
	nuevo->valor = n;
	nuevo->next = frente;
	if(vacia(frente) == 1){
		frente = nuevo;
	}
	else{
		fin->next = nuevo;
	}
	fin = nuevo;
}

void eliminar(Nodo *&frente, Nodo *&fin){
	Nodo *aux = frente;
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->next;
	}
	delete(aux);
}
