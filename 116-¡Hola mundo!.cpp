//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void resuelveCaso();

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cout << "Hola mundo.\n";
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

void resuelveCaso()
{
	
}