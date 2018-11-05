// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;
string mapa[MAX][MAX];
int dir[] = { 1,-1,0,0,0,0,-1,1 };

void resuelve(int filas, int columnas);
int resuelveCaso(int m, int n, int filas, int columnas);
int maximo(int a, int b);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int filas, columnas;
	string linea;
	while (cin >> filas && cin >> columnas) {
		cin.get();
		for (int i = 0; i < filas; ++i) {
			getline(cin, linea);
			for (int j = 0; j < columnas; ++j) {
				//cout << "Estoy en - " << i << " - " << j << " - " << linea[j] << "\n";
				mapa[i][j] = linea[j];
			}
		}
		resuelve(filas, columnas);		
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}
void resuelve(int filas, int columnas) {
	int max = 0;
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			// comparo el max actual con el nuevo
			// guardo el maximo de ellos
			max = maximo(max, resuelveCaso(i, j, filas, columnas));
		}
	}
	cout << max << "\n";
}

int resuelveCaso(int m, int n, int filas, int columnas)
{
	int ret = 1, i = 0;
	//caso base
	if (m < 0 || m >= filas)
		return 0;
	if (n < 0 || n >= columnas)
		return 0;
	if( mapa[m][n] != "#")
		return 0;	

	// compruebo todas las dir en busca de parcelas
	while (i < 4) {
		mapa[m][n] = ' ';
		ret += resuelveCaso(m + dir[i], n + dir[i + 4], filas, columnas);
		++i;
	}
	return ret;
}

int maximo(int a, int b) {
	int max = a;
	if (b > a)
		max = b;
	return max;
}