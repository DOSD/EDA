#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS
#include "pila.h"

//funcion auxiliar
bool esVocal(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	 // A IMPLEMENTAR
	Pila<char> pila;
	Lista<char> :: Iterator act = mensaje.begin(); 
	Lista<char> :: Iterator fin = mensaje.end(); 
	Lista<char> :: Iterator aux = act; 
	int constantes = 0;
	while(act != fin){
		if(!esVocal(act.elem())){
			constantes++;
			pila.apila(act.elem());
			if(constantes == 1)
				aux = act;
		}
		if(esVocal(act.elem())){
			if(constantes == 1){
				pila.desapila();
				constantes = 0;
			}
			else if(constantes > 1){
				while(aux != act){
					aux.set(pila.cima());
					pila.desapila();
					aux.next();
				}
				constantes = 0;
			}
		}
		act.next();
	}
	if(constantes > 1){
		while(aux != act){
					aux.set(pila.cima());
					pila.desapila();
					aux.next();
				}
	}
}

 
// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
