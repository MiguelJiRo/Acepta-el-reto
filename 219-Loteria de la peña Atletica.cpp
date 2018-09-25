//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void resuelve();
int numPares(int v[], int n);

const int MAX_TAM = 10000;
/*
	219 - La loteria de la peña atlética

	Implementacion en la funcion numPares.
	La complejidad es O(n) => Porque solamente se recorre el vector 1 vez
	y cada operación del vector que realiza tiene tiempo constante
*/
int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos;
	cin >> casos;

	for (int i = 0; i < casos; ++i) {
		resuelve();
	}
	
	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}
void resuelve() {
	int datos[MAX_TAM];
	int n;
	//Lectura de los datos
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> datos[i];
	}
	//Procesado
	int respuesta = numPares(datos, n);
	//Escritura de la respuesta
	cout << respuesta << "\n";
}
// { Pre: 0 <= n <= longitud(v) }
int numPares(int v[], int n) /* return ret */
{
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i] % 2 == 0) ret++;
	}
	return ret;
}
// { Post: ret =  #i: 0 <= i > n: v[i] mod 2 = 0 }