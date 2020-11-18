#include <iostream>
#include<string>
#include "pila.h"
using namespace std;

void evaluar(string exp) {

	// primera parte

	int i = 0;
	Pila<char> pila_izq;
	Pila<char> pila_der;
	while (i < exp.length())
	{
		if (i % 2 == 0) {
			pila_izq.apila(exp[i]);
		}
		else {
			pila_der.apila(exp[i]);
		}
		++i;
	}

	while (!pila_der.esVacia()) {
		pila_izq.apila(pila_der.cima());
		pila_der.desapila();
	}

	// invierto el contenido de la pila izq usando la pila der
	while (!pila_izq.esVacia())
	{
		pila_der.apila(pila_izq.cima());
		pila_izq.desapila();
	}
	
	/*while (!pila_der.esVacia())
	{
		cout << pila_der.cima();
		pila_der.desapila();
	}*/

	// tengo la frase en pila der
	// pila izq vacia

	// segunda parte

	Pila<char> pila;

	while (!pila_der.esVacia())
	{
		if (pila_der.cima() == 'a'
			|| pila_der.cima() == 'e'
			|| pila_der.cima() == 'i'
			|| pila_der.cima() == 'o'
			|| pila_der.cima() == 'u') 
		{
			while (!pila_izq.esVacia()) 
			{
				pila.apila(pila_izq.cima());
				pila_izq.desapila();
			}
			pila.apila(pila_der.cima());
		}
		else {
			pila_izq.apila(pila_der.cima());
		}
		pila_der.desapila();
	}

	while (!pila_izq.esVacia())
	{
		pila.apila(pila_izq.cima());
		pila_izq.desapila();
	}

	while (!pila.esVacia())
	{
		pila_der.apila(pila.cima());
		pila.desapila();
	}

	while (!pila_der.esVacia())
	{
		cout << pila_der.cima();
		pila_der.desapila();
	}
}

int main() {

	string expresion;
	while (getline(cin, expresion)) {
		cout << expresion << " => ";
		evaluar(expresion);
		cout << "\n";
	}

	return 0;
}

/*
BnodJo s, dBneam
aueoi
E. .n.ualn cnhuag aMda  rle
Aauirnedleiua nBo
*/