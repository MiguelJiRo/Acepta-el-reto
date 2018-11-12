// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAXIMO = 31, C = 3;
int calculadora[C][C]; 
						/*{7,8,9,
						   4,5,6,
						   1,2,3};*/

bool resuelve(int suma, int num);
bool resuelveCaso(int suma, int num, int fila, int columna);
void inicializarCalculadora();

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos;
	int a, b;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		cin >> a >> b;
		if (resuelve(a, b))
			cout << "GANA" << "\n";
		else
			cout << "PIERDE" << "\n";
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}

bool resuelve(int suma, int num) {
	int fila, columna;
	int i , j;
	bool salir = false;

	inicializarCalculadora();

	// buscar la posicion del num
	i = 0;
	while (i < C && !salir) {
		j = 0;
		while (j < C && !salir) {
			if (calculadora[i][j] == num) {
				fila = i; columna = j;
				salir = true;
			}
			++j;
		}
		++i;
	}
	/*cout << "Numero - " << calculadora[fila][columna] 
		<< " Fila - " << fila << " Columna - " << columna << "\n";
	*/
	if (!resuelveCaso(suma, num, fila, columna))
		return true;
	else
		return false;
}

bool resuelveCaso(int suma,int num, int fila, int columna) {
	int i, j;
	bool resultado;
	// caso base
	if (suma >= MAXIMO)
		return false;
	i = 0;
	while (i < C) {
		//cout << "i - " << i << "\n";
		j = 0;
		while (j < C) {
			//cout << "j - " << j << "\n";
			if (j == columna 
				&& i != fila)
				if (resuelveCaso(suma + calculadora[i][j], calculadora[i][j], i, j))
					return false;
			if (i == fila 
				&& j != columna)
				if (resuelveCaso(suma + calculadora[i][j], calculadora[i][j], i, j))
					return false;
			++j;
		}
		++i;
	}
	return true;
}

void inicializarCalculadora() {
	/*{7,8,9,
	   4,5,6,
	   1,2,3};*/

	int num = 9;
	for (int i = 0; i < C; ++i) {
		for (int j = C - 1; j >= 0; --j) {
			calculadora[i][j] = num;
			--num;
		}
	}
}