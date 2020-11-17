#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Nodo{
	public:
		int valor;
		Nodo* next;
};


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

void mostrar(Nodo *&frente, int cont){
	Nodo *temp;
	temp = frente;
	cout << endl;
	if(cont == 0)
		cout << "LA COLA ESTA VACIA" << endl;
	else
		printf("\tCOLA:\n");
	for(int i=0; i<cont; i++){
		printf("\t");
		cout << temp->valor;
		temp = temp->next;
	}
	cout << endl;
}

void tope(Nodo *&frente, Nodo *&fin, int n){
	if(frente != NULL)
		cout << "Primer Dato: " << frente->valor << endl;
	if(fin != NULL)
		cout << "Ultimo Dato: " << fin->valor << endl << endl;
	
}

int cambio(int n){
	if(n == 1){
		return 0;
	}
	return 1;
}


int capturar(){
	string dato;
	int num, i;
	
	cout << "Nuevo Elemento: ";
	cin >> dato;
	
	for(i=0; i < dato.size(); i++){
		if(isdigit(dato[i]) == 0){
			if((int)dato[i] != 0){
				cout << "DATO INCORRECTO" << endl;
				system("pause");
				system("cls");
				return -1;
			}
		}		
	}
	
	istringstream(dato) >> num;
	return num;
}





int main(){
	string opc;
	int num, f=1, m=1, t=1, cont = 0;
	Nodo *frente = NULL,*fin = NULL;
	
	while(f==1){
		system("cls");
		if(m == 1){
			mostrar(frente, cont);
			if(frente != NULL)
				cout << endl;
		}
		if(t == 1){
			tope(frente, fin, cont);
			if(frente != NULL || fin != NULL)
				cout << endl;
		}
		cout << "----------Seleccione una Opcion---------" << endl;
		cout << "1) Agregar" << endl;
		cout << "2) Eliminar" << endl;
		cout << "3) Mostrar Tope" << endl;
		cout << "4) Mostrar Pila" << endl;
		cout << "5) Salir" << endl;
		cin >> opc;
		
		if(opc == "1"){
			num = capturar();
			if(num != -1){
				cont++;
				agregar(frente, fin, num);
			}
			
		}
		else if(opc == "2"){
			if(cont == 0){
				cout << endl << "No puedes quitarte elementos a una cola vacia" << endl;
				system("pause");
			}
			else{
				eliminar(frente, fin);
				cont--;
			}
		}
		else if(opc == "3"){
			t = cambio(t);
		}
		else if(opc == "4"){
			m = cambio(m);
		}
		else if(opc == "5"){
			system("cls");
			cout << "FIN DEL PROGRAMA" << endl;
			f=0;
		}
		else{
			cout << "Opcion Incorrecta" << endl;
			system("pause");
			system("cls");
		}	
	}
	
	return 0;
}
