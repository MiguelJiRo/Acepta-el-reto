// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void resuelve(int num);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos, num;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		cin >> num;
		resuelve(num);
		cout << "\n";
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}

void resuelve(int num) {
	int r;
	if (num / 6 == 0) 
		cout << num;
	else {
		resuelve(num / 6);
		cout << num % 6;
	}
}
