//Miguel Jiménez Rodríguez

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int resuelveCaso(int a, int b[]);

int main() {
	// Para la entrada por fichero.
	//#ifndef DOMJUDGE
	//std::ifstream in("casos.txt");
	//auto cinbuf = std::cin.rdbuf(in.rdbuf());
	//#endif

	int numCasos;
	int arrayMontes[100000];

	cin >> numCasos;
	while (numCasos != 0) {
		for (int i = 0; i < numCasos; ++i) {
			cin >> arrayMontes[i];
		}
		cout << resuelveCaso(numCasos, arrayMontes) << "\n";
		cin >> numCasos;
	}
	//#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	//#endif
	return 0;
}


// { Pre: 0 <= a <= longitud(b) }
int resuelveCaso(int a, int b[])
{	
	/*int cont = 0;
	bool correcto = true;
	for (int i = 0; i < a; ++i) {
		for (int j = i; j < a - 1 && correcto; ++j) {
			if (b[i] <= b[j+1]) 
				correcto = false;
		}
		if (correcto) cont++;
		correcto = true;
	}
	cout << cont << endl;*/

	int cont = 1, siguiente = b[a - 1];

	/* { I : a - 2 <= i <= 0
			^ cont : 0 <= i < j < a : v[i] > v[j]}
	*/
	for (int i = a - 2; i >= 0; --i) {
		if (b[i] > siguiente) {
			cont++;
			siguiente = b[i];
		}
	}
	return cont;
}

// { Post: cont : # i : 0 <= i < j < a : v[i] > v[j] }