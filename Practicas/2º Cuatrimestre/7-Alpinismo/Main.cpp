#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void tiempoAyuda_aux(const Arbin<char>& a,int &tiempo,int cont){
	if(!a.esVacio()){
		if(a.raiz() == 'X')
			tiempo = tiempo + cont*2;
		cont++;
		tiempoAyuda_aux(a.hijoIz(),tiempo,cont);
		tiempoAyuda_aux(a.hijoDer(),tiempo,cont);
	}
}

int tiempoAyuda(const Arbin<char>& falda) {
	// A IMPLEMENTAR
	int result = 0;
	tiempoAyuda_aux(falda,result,0);
	return result;
}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF)  {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}