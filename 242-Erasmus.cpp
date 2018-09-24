//Miguel Jiménez Rodríguez

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void resuelveCaso(long long int a, int b[], long long int c);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	long long int numCasos,total = 0;
	int arrayCasos[100000];

	cin >> numCasos;
	while (numCasos != 0) {
		for (int i = 0; i < numCasos; ++i) {
			cin >> arrayCasos[i];
			total += arrayCasos[i];
		}
		resuelveCaso(numCasos, arrayCasos, total);
		total = 0;
		cin >> numCasos;
	}
	
	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

void resuelveCaso(long long int a, int b[], long long int c)
{	
	long long int cont = 0, aux = c;
	for (int i = 0; i < a; i++) {
		//resto mi posicion actual
		aux -= b[i];
		//multiplico por la suma del total restante
		cont += aux * b[i];
	}
	cout << cont << endl;
}