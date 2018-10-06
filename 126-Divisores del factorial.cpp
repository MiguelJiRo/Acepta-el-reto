//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_TAM = 10000;

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int p, n;
	cin >> p >> n;
	while (p > -1 || n > -1) {
		if ((p == 1 || p <= n) && (p >= 0 && n >= 0)) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
		cin >> p >> n;
	}
	
	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}