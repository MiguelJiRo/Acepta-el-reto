// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1000000;
void resuelve(int m, int n);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	
	int m, n;

	cin >> m >> n;

	while (m > 0 && n >= 0) {

		resuelve(m, n);
		cin >> m >> n;
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}

void resuelve(int m, int n)
{
	
	int cMax = 0, contUnos = 0, contCeros = 0, num;
	vector<int> numeros;

	int j = 0;
	while( j < m ) {
		cin >> num;
		numeros.push_back(num);
		++j;
	}
	int i = 0;
	while( i < numeros.size() ) {

		if (numeros[i] == 1) {
			contUnos++;
			contUnos += contCeros;
			contCeros = 0;
			if (contUnos > cMax)
				cMax = contUnos;
		}
		else {
			if (contUnos > 0) {
				contCeros++;
				if (contCeros > n) {
					if (contUnos > cMax)
						cMax = contUnos;
					contCeros = 0;
					contUnos = 0;
				}
			}
		}
		++i;
	}
	cout << cMax << endl;
}