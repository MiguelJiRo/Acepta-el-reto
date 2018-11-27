// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

long long resuelve(vector<int> &v, int n, int m, int o, vector<int> &w);
long long resuelveCaso(vector<int> &a1, vector<int> &a2, vector<int> &a3);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	int casos;
	cin >> casos;
	while (casos != 0) {
		vector<int> v(casos), w(casos);
		for (int i = 0; i < casos; ++i)
			cin >> v[i];
		cout << resuelve(v, 0, v.size(), v.size()/2,w) << "\n";
		cin >> casos;
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}

long long resuelve(vector<int> &v, int n, int m, int o, vector<int> &w) {
	long long cont = 0;
	// caso base
	if (m - n <= 1) {
		w[0] = v[n];
		return cont;
	}
	vector<int> a1(o - n);
	vector<int> a2(m - o);
	// casos recursivos
	cont += resuelve(v, n, o, (n + o) / 2,a1);
	cont += resuelve(v, o, m, (m + o) / 2,a2);
	cont += resuelveCaso(a1,a2,w);
	return cont;
}

long long resuelveCaso(vector<int> &a1, vector<int> &a2, vector<int> &a3) {
	long long cont = 0;
	int i = 0, j = 0, k = 0;
	while (i < a1.size() && j < a2.size()) {
		if (a1[i] <= a2[j]) {
			cont += j;
			a3[k] = a1[i]; 				
			++i;
		}
		else {
			a3[k] = a2[j]; 
			++j;
		}
		++k;
	}
	//cout << "1- " << cont << "\n";
	// a1
	while (i < a1.size()) {
		cont += j;
		a3[k] = a1[i]; 		
		++i; ++k;
	}
	//cout << "2- " << cont << "\n";
	// a2
	while (j < a2.size()) {
		a3[k] = a2[j];
		++j; ++k;
	}
	//cout << "3- " << cont << "\n";
	return cont;
}