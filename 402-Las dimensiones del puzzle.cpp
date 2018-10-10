//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

const int MAX_TAM = 10000;

int resuelve(int n);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos, piezas;
	cin >> casos;
	while (casos != 0) {
		cout << resuelve(casos) << "\n";
		cin >> casos;
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

int resuelve(int n) {
	int r;
	if (n == 0) return 0;
	else {
		r = sqrt(n);
		while (n % r != 0)
		{
			--r;
		}
	}
	return (n / r);
}