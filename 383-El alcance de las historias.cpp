#include <iostream>
#include <fstream>

using namespace std;

int alcance(int n);

int v[300000];

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	/*unsigned t0, t1;
	t0 = clock();*/

	int casos, n;
	cin >> casos;
	while (casos--) {
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cout << alcance(n) << "\n";
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

int alcance(int n) {
	int ret = v[0] - v[1];
	int posMax = 0;
	int i = 1;

	while (i < n) {
		if (v[posMax] - v[i] > ret)
			ret = v[posMax] - v[i];
		if (v[i] > v[posMax])
			posMax = i;

		++i;
	}

	return ret;
}