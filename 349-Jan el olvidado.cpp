// Miguel Jiménez Rodríguez
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int resuelve();

int main() {
	int casos;
	int i = 0;

	cin >> casos;

	while (i < casos) {
		cout << resuelve() << '\n';
		cin.get();
		i++;
	}

	return 0;
}

int resuelve() {
	char c;
	cin >> c;

	if (c == '+')
		return resuelve() + resuelve();
	if (c == '*')
		return resuelve() * resuelve();
	if (c == '/')
		return resuelve() / resuelve();
	if (c == '-')
		return resuelve() - resuelve();

	return  c - '0';
}