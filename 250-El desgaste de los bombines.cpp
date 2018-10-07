//Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_TAM = 10000;

int resuelve(int v[], int s, int r, int n);
int positivo(int a);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos, v[MAX_TAM];
	int suma, resta;
	cin >> casos;
	while (casos != 0) 
	{
		suma = 0;
		resta = 0;
		for (int i = 0; i < casos; ++i)
		{
			cin >> v[i];
			if (v[i] >= 0)
				suma += v[i];
			else
				resta += v[i];
		}
		if ((suma + resta) == 0) {
			cout << "0" << "\n";
		}
		else
			cout << resuelve(v, suma, resta, casos) << "\n";
		cin >> casos;
	}


	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/
	return 0;
}

int resuelve(int v[], int s, int r, int n) {
	int i = 0, ret = 0;
	int totalparaR = s+r;
	int totalparaS = 0;
	int auxsuma = s+r;
	
	while (i < n) {
		totalparaR -= v[i];
		totalparaS += v[i];
		
		if (positivo(totalparaS - totalparaR) < positivo(auxsuma))
		{
			ret = i + 1;
			auxsuma = positivo(totalparaS - totalparaR);
		}
		++i;
	}
	return ret;
}

int positivo(int a) {
	if (a < 0)
		return -a;
	else
		return a;
}