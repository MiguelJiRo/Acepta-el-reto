//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_TAM = 10000;

void resuelve();

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos;

	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		resuelve();
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

void resuelve() {
	int dondestoy;
	int contabajo = 0, contarriba = 0;
	int salto, dondevoy;
	int i = 0;
	cin >> salto;	
	cin >> dondestoy;
	while (i < salto - 1) {
		cin >> dondevoy;
		if (dondestoy < dondevoy)
			contarriba++;
		else if (dondestoy > dondevoy)
			contabajo++;
		dondestoy = dondevoy;
		++i;
	}
	cout << contarriba << " " << contabajo << "\n";
}