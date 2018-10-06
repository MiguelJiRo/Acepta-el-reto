//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_TAM = 10000;
bool resuelve();

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	while (resuelve());

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

bool resuelve() {
	int primerpiso, segundopiso, contador=0;
	cin >> primerpiso;
	if (primerpiso < 0) return false;
	else {
		cin >> segundopiso;
		while (segundopiso != -1) {
			if (primerpiso < segundopiso)
				contador += segundopiso - primerpiso;
			else
				contador += primerpiso - segundopiso;
			primerpiso = segundopiso;
			cin >> segundopiso;
		}
		cout << contador << "\n";
	}
}