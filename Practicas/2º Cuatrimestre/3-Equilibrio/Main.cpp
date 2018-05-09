#include <iostream>
#include <string>
#include "Pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
	// A IMPLEMENTAR
	Pila<char> miPila;
	bool equilibrada = true;
	int i = 0;
	while(equilibrada && i < cadena.length()){
		if(cadena[i] == '{' || cadena[i] == '[' || cadena[i] == '(')
			miPila.apila(cadena[i]);
		else if(cadena[i] == '}' || cadena[i] == ']' || cadena[i] == ')'){
			if(miPila.esVacia())
				equilibrada = false;
			else{ 
				if(cadena[i] == '}'){
					if(miPila.cima() != '{')
						equilibrada = false;
					else miPila.desapila();
				}
				else if(cadena[i] == ']'){
					if(miPila.cima() != '[')
						equilibrada = false;
					else miPila.desapila();
				}
				else if(cadena[i] == ')'){
					if(miPila.cima() != '(')
						equilibrada = false;
					else miPila.desapila();
				}
			}
		}
		++i;
	}
	if(i == cadena.length() && !miPila.esVacia())
		equilibrada = false;

	return equilibrada;
}


int main() {
	string cadena;
    while(getline(cin, cadena)) {
      if(esEquilibrada(cadena))
        cout << "EQUILIBRADA" << endl;
      else
        cout << "NO_EQUILIBRADA" << endl;		  
	}
	return 0;
}