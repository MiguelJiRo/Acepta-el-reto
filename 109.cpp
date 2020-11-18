#include <iostream>
#include <string>
#include "lista.h"
using namespace std;

struct partido {
	string pareja_uno;
	int set_pareja_uno;
	string pareja_dos;
	int set_pareja_dos;
};

struct liga {
	string pareja;
	int puntaje;
};

struct totales {
	int partidos_totales;
	int partidos_jugados;
	int empates;
};

void actualizarTablas(Lista<liga> &equipos, int puntos, string pareja)
{
	Lista<liga>::Iterator itEscritura = equipos.begin();
	liga nuevaLiga;
	bool encontrado = false;

	while (itEscritura != equipos.end())
	{
		if (itEscritura.elem().pareja == pareja)
		{
			nuevaLiga = itEscritura.elem();
			nuevaLiga.puntaje += puntos;

			itEscritura.set(nuevaLiga);
			encontrado = true;
		}
		itEscritura.next();
	}

	if (!encontrado) {
		nuevaLiga.puntaje = puntos;
		nuevaLiga.pareja = pareja;
		equipos.pon_final(nuevaLiga);
	}
}

void ligaDePadel(Lista<partido> &liga_partidos, Lista<liga> &equipos, totales ttls) 
{
	Lista<partido>::ConstIterator itLectura_principal = liga_partidos.cbegin();

	while (itLectura_principal != liga_partidos.cend()) {
		// gana pareja 1
		if (itLectura_principal.elem().set_pareja_uno >
			itLectura_principal.elem().set_pareja_dos)
		{
			actualizarTablas(equipos, 2, itLectura_principal.elem().pareja_uno);
			actualizarTablas(equipos, 1, itLectura_principal.elem().pareja_dos);
		}
		// gana pareja 2
		else if (itLectura_principal.elem().set_pareja_uno <
			itLectura_principal.elem().set_pareja_dos)
		{
			actualizarTablas(equipos, 1, itLectura_principal.elem().pareja_uno);
			actualizarTablas(equipos, 2, itLectura_principal.elem().pareja_dos);
		}
		// empate
		else {
			ttls.empates++;
		}

		itLectura_principal.next();
	}
}

void mostrarResultado(Lista<liga> equipos, totales ttls)
{
	string ganador;
	int puntos_maximo = -1;

	Lista<liga>::ConstIterator itLectura = equipos.cbegin();

	while (itLectura != equipos.cend()) {
		if (itLectura.elem().puntaje > puntos_maximo) 
		{
			ganador = itLectura.elem().pareja;
			puntos_maximo = itLectura.elem().puntaje;
		}
		itLectura.next();
	}

	cout << ganador << " " << ttls.partidos_totales - ttls.partidos_jugados << "\n";
	cout << "EMPATE " << ttls.empates << "\n";
}

void resetear_listas(Lista<partido> &liga_partidos, Lista<liga> &equipos) 
{
	Lista<partido> liga_partidos_new;
	Lista<liga> equipos_new;

	liga_partidos = liga_partidos_new;
	equipos = equipos_new;

	/*Lista<partido>::Iterator itEscritura = liga_partidos.begin();
	while (itEscritura != liga_partidos.end())
	{
		liga_partidos.eliminar(itEscritura);
		itEscritura.next();
	}

	Lista<liga>::Iterator itEscritura_dos = equipos.begin();
	while (itEscritura_dos != equipos.end())
	{
		equipos.eliminar(itEscritura_dos);
		itEscritura_dos.next();
	}*/
}

int main() {
	
	Lista<partido> liga_partidos;
	Lista<liga> equipos;

	string nombre, nombre_liga;

	partido partido_nuevo;
	totales ttls;

	cin >> nombre;
	while (nombre != "FIN") 
	{
		ttls.empates = 0;
		ttls.partidos_jugados = 0;
		ttls.partidos_totales = 0;

		resetear_listas(liga_partidos, equipos);

		nombre_liga = nombre;
		cin >> nombre;

		while (nombre != "FIN") 
		{
			partido_nuevo.pareja_uno = nombre;
			cin >> partido_nuevo.set_pareja_uno;
			cin >> partido_nuevo.pareja_dos;
			cin >> partido_nuevo.set_pareja_dos;

			liga_partidos.pon_final(partido_nuevo);

			ttls.partidos_jugados++;

			cin >> nombre;
		}

		ligaDePadel(liga_partidos, equipos, ttls);
		//cout << nombre_liga << "\n";

		ttls.partidos_totales = equipos.longitud() * (equipos.longitud() - 1);
		mostrarResultado(equipos, ttls);

		cin >> nombre;
	}
	return 0;
}

/*
ENTRADA

Junior
Buenisimos 3 Malisimos 0
Buenillos 2 Malillos 1
Buenillos 3 Malisimos 0
Buenisimos 3 Malillos 0
Buenisimos 2 Buenillos 1
Malisimos 0 Buenisimos 3
Malillos 1 Buenillos 2
Malisimos 0 Buenillos 3
Malillos 0 Buenisimos 3
Buenillos 1 Buenisimos 2
FIN
Senior
Abuelos 3 Abueletes 0
Abueletes 2 Abuelos 1
FIN
FIN
*/

/*
SALIDA

Buenisimos 2
EMPATE 0
*/