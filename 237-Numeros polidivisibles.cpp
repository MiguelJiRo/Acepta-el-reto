// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool resuelve(long long n, int &i);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	long long numero;
	while (cin >> numero) {
		int i = 0;
		if (resuelve(numero, i))
			cout << "POLIDIVISIBLE" << "\n";
		else
			cout << "NO POLIDIVISIBLE" << "\n";
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}

bool resuelve(long long n, int &i) {
	if (n / 10 == 0) {
		i++;
		return n % i == 0;
	}

	bool p = resuelve(n / 10, i);
	i++;
	return p && n % i == 0;
}
