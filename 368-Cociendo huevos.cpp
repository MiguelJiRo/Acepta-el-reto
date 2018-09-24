//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void resuelveCaso(int h, int c);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int h,c;
	cin >> h >> c;
	while (h != 0 && c != 0) {
		resuelveCaso(h, c);
		cin >> h >> c;
	}
	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

void resuelveCaso(int h, int c)
{
	int cont = 1;
	h -= c;
	while (h > 0) {
		h -= c;
		cont++;
	}
	cout << cont * 10 << endl;
}