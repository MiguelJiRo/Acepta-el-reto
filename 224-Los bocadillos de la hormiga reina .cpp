#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resuelve(long long v[], long long n);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	/*unsigned t0, t1;
	t0 = clock();*/

	long long numCasos;
	long long arrayCachitos[100000];
	while (cin >> numCasos && numCasos != 0) {
		for (int i = 0; i < numCasos; i++) {
			cin >> arrayCachitos[i];
		}
		resuelve(arrayCachitos, numCasos);
	}

	/*t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;*/

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}

void resuelve(long long v[], long long n) {
	long long total = 0, posicion = 0;
	bool correcto = false;
	int i = n - 1;
	while(i >= 0) 
	{
		if (v[i] == total) {
			posicion = i;
			correcto = true;
		}
		total += v[i];
		--i;
	}
	if (correcto) cout << "SI" << " " << posicion + 1 << "\n";
	else cout << "NO\n";
}