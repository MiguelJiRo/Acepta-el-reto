#include "cola.h"
#include <iostream>
#include <string>
using namespace std;

void supervivientes(Cola<string> cola_uno, int camas, int palabras, int tam) {
	Cola<string> cola_dos;
	int save_palabras = palabras;
	bool c_uno = true, c_dos = false;

	while (tam != camas) {
		save_palabras--;
		if (save_palabras == 0) 
		{
			save_palabras = palabras;

			if (c_uno) {
				tam--;
				cout << "elimino a => " << cola_uno.primero() << "\n";
				cola_uno.quita();
			}
			else if (c_dos) {
				tam--;
				cout << "elimino a => " << cola_dos.primero() << "\n";
				cola_dos.quita();
			}
		}
		else {
			if (c_uno) {
				cola_dos.pon(cola_uno.primero());
				cola_uno.quita();
			}
			else if(c_dos){
				cola_uno.pon(cola_dos.primero());
				cola_dos.quita();
			}
		}
		if (cola_uno.esVacia()) {
			c_dos = true;
			c_uno = false;
		}
		else if (cola_dos.esVacia()) {
			c_uno = true;
			c_dos = false;			
		}
	}

	if (c_uno) 
	{
		while (!cola_dos.esVacia()) {
			cout << cola_dos.primero() << " ";
			cola_dos.quita();
		}
		while (!cola_uno.esVacia()) {
			cout << cola_uno.primero() << " ";
			cola_uno.quita();
		}
	}
	else 
	{
		while (!cola_uno.esVacia()) {
			cout << cola_uno.primero() << " ";
			cola_uno.quita();
		}
		while (!cola_dos.esVacia()) {
			cout << cola_dos.primero() << " ";
			cola_dos.quita();
		}
	}
	cout << "\n";
}

/*
5
Anastasio Ignacio Felipe Borja Daniel Cesar F 2 3
Javier Ramiro Luis Rosa Carmen Paola Josefa F 0 3
Petra Santiago Pepi F 2 20
Merche Juanjo Miriam Pilar Marina Ovidio Rafael Eustaquio F 4 7
*/

int main() {
	int n, camas, palabras, tam = 0;
	Cola<string> cola;
	string nombre;

	cin >> n;
	while (n > 0) {
		cin >> nombre;
		while (nombre != "F") {
			cola.pon(nombre);
			cin >> nombre;
			tam++;
		}
		cin >> camas >> palabras;
		if (camas == 0) {
			cout << "NADIE TIENE CAMAS\n";
		}
		else {
			supervivientes(cola, camas, palabras, tam);
		}
		
		while (!cola.esVacia())
			cola.quita();
		n--;
	}

	return 0;
}
