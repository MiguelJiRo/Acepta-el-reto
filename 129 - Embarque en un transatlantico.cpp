//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

const int MAX_TAM = 1000000;

int resuelveEmbarque(int v[], int n, int c);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos, acciones;
	int v[MAX_TAM];
	string asunto;
	int cubierta;

	cin >> casos;	
	while (casos != 0)
	{
		for (int i = 0; i < casos; ++i) {
			cin >> v[i];
		}
		cin >> acciones;
		for (int j = 0; j < acciones; ++j) 
		{
			cin >> asunto >> cubierta;

			if (asunto == "CONSULTA") {
				cout << v[cubierta - 1] << "\n";
			}
			else {
				int n = resuelveEmbarque(v, casos, cubierta);
				cout << n << "\n";
				casos = n;
			}	
		}
		cout << "*\n";
		cin >> casos;
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

int resuelveEmbarque(int v[], int n, int c)
{
	int i = 0, j = 1;

	if (n == 1 && v[i] != c)
		i = 1;
	else {
		while (j < n && i < n) {
			if (v[i] == c) {
				if (v[j] != c && j > i) {
					swap(v[i], v[j]);
					++i; ++j;
				}
				else ++j;
			}
			else ++i;
		}
	}
	return i;
}