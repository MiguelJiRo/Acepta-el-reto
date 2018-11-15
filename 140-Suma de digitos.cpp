// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool resuelve();
int resuelveCaso(int num);

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
	int num;
	cin >> num;
	if (num < 0)
		return false;
	int suma = resuelveCaso(num);
	cout << " = " << suma << "\n";
	return true;
}

int resuelveCaso(int n) {
	int num;
	if (n / 10 == 0) {
		num = n;
		cout << n;
	}
	else {
		num = n % 10 + resuelveCaso(n / 10);
		cout << " + " << n % 10;
	}
	return num;
}