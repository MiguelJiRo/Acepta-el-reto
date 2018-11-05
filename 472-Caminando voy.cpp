// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 1000000;
bool resuelve(int v[], int n, int d);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	
	int desnivel, casos;
	int v[MAX];

	while (cin >> desnivel) {
		cin >> casos;
		for (int i = 0; i < casos; ++i) {
			cin >> v[i];
		}
		if (resuelve(v, casos, desnivel))
			cout << "APTA\n";
		else
			cout << "NO APTA\n";
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}

bool resuelve(int v[], int n, int d)
{
	int i = 1;
	int suma = 0;
	while (i < n) {
		if (v[i] > v[i - 1])
			suma += v[i] - v[i - 1];
		else
			suma = 0;
		if (suma > d)
			return false;
		++i;
	}
	return true;
}