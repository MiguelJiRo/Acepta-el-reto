// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void resuelveCaso();

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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	/*t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;*/

	/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}

void resuelveCaso()
{
	int pesoNieve, numPalmeras;
	int palmeras[100000];
	
	cin >> pesoNieve >> numPalmeras;

	int i = 0, j = 0, longitud = 0, contadorPalmeras = 0;
	while (numPalmeras--) 
	{
		cin >> palmeras[j];
		if (palmeras[j] >= pesoNieve) 
		{
			contadorPalmeras++;
			while (contadorPalmeras > 5) 
			{
				if (palmeras[i] >= pesoNieve) contadorPalmeras--;
				i++;
			}
		}
		if (longitud < (j - i + 1)) 
			longitud = j - i + 1;
		j++;
	}
	cout << longitud << "\n";
}