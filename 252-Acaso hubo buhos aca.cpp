// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s;

bool resuelve( int a, int b);

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	
	getline(cin, s);
	while (s != "XXX") {
		if (resuelve(0, s.length() - 1))
			cout << "SI\n";
		else
			cout << "NO\n";
		getline(cin, s);
	}

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif*/

	return 0;
}

bool resuelve( int a, int b) {
	if (a >= b)
		return true;

	while (!isalpha(s[a]))
		++a;
	while (!isalpha(s[b]))
		--b;

	string uno, dos;
	uno = tolower(s[a]);
	dos = tolower(s[b]);
	
	//cout << " uno - " << uno << " dos - " << dos << "\n";
	return resuelve( ++a, --b) && (uno == dos);
}
