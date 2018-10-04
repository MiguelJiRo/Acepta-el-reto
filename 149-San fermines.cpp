//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//int resuelve(int v[], int n);
int resuelve(int a, int n);

const int MAX_TAM = 10000;

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos, velocidad;
	while (cin >> casos) {
		int mayor = 0;
		for (int i = 0; i < casos; ++i) {
			cin >> velocidad;
			mayor = resuelve(mayor, velocidad);
		}
		cout << mayor << "\n";
	}


	
	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

/*
// { Pre: 0 <= n <= longitud(v) }
int resuelve(int v[], int n) {
	int ret = 0 ,i = 0;

	
	//{ I : 0 <= i < n ^ ret : max j : 0 <= j < n : v[j] }
	
	while (i < n) {
		if (v[i] > ret)
			ret = v[i];
		++i;
	}

	return ret;
}
// { Post: ret : max i : 0 <= i < n : v[i] }
*/

int resuelve(int mayor, int velocidad)
{
	if (velocidad > mayor) 
		return velocidad; 
	else 
		return mayor; 
}