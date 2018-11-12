// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool resuelve(int pi, int di, int pd, int dd, int &suma);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int pi, di, pd, dd, suma;
	while (cin >> pi >> di >> pd >> dd && !(di == 0 && pd == 0)) {
		if (resuelve(pi, di, pd, dd, suma)) {
			cout << "SI" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}

bool resuelve(int pi, int di, int pd, int dd, int &suma) {
	bool izq = true, dex = true;
	int pii, dii, pdi, ddi;
	int pid, did, pdd, ddd;

	if (pi == 0) {
		cin >> pii >> dii >> pdi >> ddi;
		izq = resuelve(pii, dii, pdi, ddi, pi);
	}
	if (pd == 0) {
		cin >> pid >> did >> pdd >> ddd;
		dex = resuelve(pid, did, pdd, ddd, pd);
	}
	suma = pi + pd;
	if (izq && dex && pi*di == pd * dd)
		return true;
	else
		return false;
}
