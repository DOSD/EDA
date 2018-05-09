#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool esHoja(const Arbin<int>& cuenca){
	return cuenca.hijoIz().esVacio() && cuenca.hijoDer().esVacio();
}
void numeroTramosNavegables_aux(const Arbin<int>& cuenca, int &resul,int &caudal){
	if(esHoja(cuenca))
		caudal=1;
	else{
		int caudIz=0,caudDder=0;
		if(!cuenca.hijoIz().esVacio())
			numeroTramosNavegables_aux(cuenca.hijoIz(), resul,caudIz);
		if(!cuenca.hijoDer().esVacio())
			numeroTramosNavegables_aux(cuenca.hijoDer(), resul,caudDder);
		caudal = caudIz +  caudDder + cuenca.raiz();
		if(caudal < 0)
			caudal = 0;
		if(caudal >= 3)
			resul++;
	}
}


int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int navegables = 0;
	int caudal=0;
	numeroTramosNavegables_aux(cuenca,navegables,caudal);
	if(caudal >= 3)
		navegables--;
	return navegables;
}


Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}