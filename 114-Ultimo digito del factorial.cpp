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
	int factorial, total;
	cin >> factorial;

	if(factorial > 4)
		total = 0;
	else {
		total = 1;
		while (factorial > 1) {
			total *= factorial;
			factorial--;
		}
	}
	cout << total % 10 << endl;
}