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

	while(resuelve());

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

bool resuelve() {
	long long casos, down = 0, up = 0, primero, segundo;
	cin >> casos;
	if (casos == 0)
		return false;
	else if (casos >= 2) {
		cin >> primero;
		int i = 1; 
		down = 0; 
		up = 0;
		while (i < casos) 
		{
			cin >> segundo;
			if (primero > segundo || primero == segundo)
				up++;
			if (primero < segundo || primero == segundo)
				down++;
			primero = segundo;
			++i;
		}		
		if (down == 0 || up == 0)			
			cout << "DALTON" << "\n";				
		else
			cout << "DESCONOCIDOS" << "\n";
	}
	return true;
}