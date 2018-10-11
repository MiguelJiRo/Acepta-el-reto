//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

const int MAX_TAM = 200000;

int resuelve(int v[], int n);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos;
	int v[MAX_TAM];

	cin >> casos;
	while (casos != 0) {
		for (int i = 0; i < casos; ++i)
			cin >> v[i];
		cout << resuelve(v, casos) << "\n";
		cin >> casos;
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

int resuelve(int v[], int n) {
	int ret = 1;
	int i = 1;
	int max = v[0];
	int aux = v[0];
	while (i < n) {
		// si es mayor
		if (v[i] > max)
			max = v[i];
		// si es menor o igual
		if (v[i] <= aux)
		{
			ret = i + 1;
			aux = max;
		}
		++i;
	}
	return ret;
}