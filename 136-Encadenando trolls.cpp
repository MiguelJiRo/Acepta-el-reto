// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool resuelve();
int numCortes(int numEslabones, int fuerza);

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
	int numEslabones, fuerza;
	cin >> fuerza >> numEslabones;
	fuerza *= 2;

	if (fuerza == 0)
		return false;

	cout << numCortes(numEslabones, fuerza) << "\n";
	return true;
}

int numCortes(int numEslabones, int fuerza) {
	if (numEslabones <= fuerza)
		return 0;
	int ladoCorto = numEslabones / 3;
	int ladoLargo = numEslabones - ladoCorto;

	int a = numCortes(ladoCorto, fuerza);
	int b = numCortes(ladoLargo, fuerza);
	return a + b + 1;
}