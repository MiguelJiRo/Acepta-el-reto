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
		resuelveCaso();
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

void resuelveCaso()
{
	long long casos, maximo = 0, maxtotal = 0, minimo = 9223372036854775807, mintotal = 0;
	int n = 0;

	while (cin >> casos && casos != 0) {
		if (casos < minimo) {
			minimo = casos;
			mintotal = 1;
		}
		else if (casos == minimo)
			mintotal++;

		if (casos > maximo) {
			maximo = casos;
			maxtotal = 1;
		}
		else if (casos == maximo)
			maxtotal++;
	}

	cout << minimo << " " << mintotal << " " << maximo << " " << maxtotal << "\n";
}