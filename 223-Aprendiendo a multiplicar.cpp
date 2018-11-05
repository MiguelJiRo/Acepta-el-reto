#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resuelveCaso();
int aprendiendoAMultiplicar(vector<int> v, int n, int &intervaloInferior, int &intervaloSuperior);
int maximo(int r, int k, int s, int &indiceInferior, int &indiceSuperior);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	/*unsigned t0, t1;
	t0 = clock();*/

	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	/*t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;*/

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}

void resuelveCaso() {
	//resuelve aqui tu caso
	int numElementos, elemento;
	int indiceInferior = 0, indiceSuperior = 0;
	bool hayIntervalo = false;
	//Lee los datos
	cin >> numElementos;

	vector<int> v;

	for (int i = 0; i < numElementos; i++)
	{

		cin >> elemento;
		v.push_back(elemento);
	}
	//Calcula el resultado
	int r = aprendiendoAMultiplicar(v, numElementos, indiceInferior, indiceSuperior);
	//Escribe el resultado

	if (r > 0)
		cout << r << " -> [" << indiceInferior << "," << indiceSuperior << "]\n";
	else cout << "SIGUE BUSCANDO\n";
}

int aprendiendoAMultiplicar(vector<int> v, int n, int &indiceInferior, int &indiceSuperior) {
	int k = 0, r = 0, s = 0;
	while (k < n) {
		if (v[k] != 0) {
			r = maximo(r, k, s, indiceInferior, indiceSuperior);
		}
		else
			s = k + 1;
		k++;
	}
	return r;
}

int maximo(int r, int k, int s, int &indiceInferior, int &indiceSuperior) {
	if (r < k - s + 1)
	{
		indiceSuperior = k;
		indiceInferior = s;
		return k - s + 1;
	}
	else return r;
}