// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int resuelve(int n);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int numero;
	while (cin >> numero) {
		int suma = resuelve(numero);
		cout << suma << "\n";
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}

int resuelve(int n) {
	if (n == 1)
		return 4;
	return 4 * n + 4 * resuelve(n / 2);
}
