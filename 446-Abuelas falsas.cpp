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

	 // , arrayNombres[MAX_TAM];
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		if(resuelve())
			cout << "VERDADERA\n";
		else
			cout << "FALSA\n";
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

bool resuelve() {
	string nombrereal, siguientenombre;
	int numnietos;
	char c;

	cin >> nombrereal;
	cin.get(c);
	cin >> numnietos;
	if (numnietos > 1) {
		for (int j = 0; j < numnietos-1; ++j) {
			cin.get(c);
			cin >> siguientenombre;
			if (siguientenombre == nombrereal)
			{
				getline(cin, siguientenombre);
				return false;				
			}
		}
		cin.get(c);
		cin >> siguientenombre;

		if (siguientenombre == nombrereal)
			return true;
		else {
			return false;
		}
				
	}
	else {
		getline(cin, siguientenombre);
		return false;
	}
}