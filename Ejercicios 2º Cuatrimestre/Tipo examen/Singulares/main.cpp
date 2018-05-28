/**
  NOMBRE Y APELLIDOS:
  LABORATORIO:
  PUESTO:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

void numero_singulares_aux(Arbin<int> a,int &singulares,int antepasados, int &descendientes){

	if(!a.esVacio()) {
		numero_singulares_aux(a.hijoIz(), singulares, antepasados+a.raiz(), descendientes);
		int desDr = 0;
		numero_singulares_aux(a.hijoDer(), singulares, antepasados+a.raiz(), desDr);

		if (antepasados == (descendientes + desDr))
				singulares++;
		descendientes += a.raiz() + desDr;
	}
}

/**
COMPLEJIDAD: Explica aqu� justificadamente cu�l es la complejidad de
esta funci�n
***A COMPLETAR***
*/
unsigned int numero_singulares(Arbin<int> a) {
	// A IMPLEMENTAR
	int res = 0;
	int dummy = 0;
	numero_singulares_aux(a,res,0,dummy);

	return res;
}

/**
  COMPLEJIDAD: Explica aqu� justificadamente cu�l es la complejidad de 
               esta funci�n
			   ***A COMPLETAR***
*/

Arbin<int> lee_arbol(istream& in) {
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
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

/**
Este programa lee �rboles de la entrada est�ndar, 
codificados de acuerdo con las siguientes reglas:
(1) El �rbol vac�o se codifica como #
(2) Los �rboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los �rboles complejos se codifican como (IvD),
    con I la codificaci�n del hijo izquierdo,
	v el valor de la ra�z, y D la codificaci�n
	del hijo derecho.
Para cada �rbol le�do, escribe en la salida est�dar
el n�mero de nodos singulare de dicho �rbol.
	
Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el �rbol vac�o. Al no tener nodos,
un �rbol vac�o tiene 0 nodos sigulares.
-El segundo representa un �rbol con un �nico nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene 
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0. 
-El tercero representa otro �rbol con un �nico nodo, cuyo
valor es 5. Por la misma raz�n que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente �rbol:
     
	       1
		  /  \
		  3  -4
         / \  
        4  -3 

Este �rbol tiene 2 nodos sigulares: la ra�z, y la ra�z del hijo 
izquierdo. 

Por tanto, la salida del programa para estos casos ser�:

0
1
1
2

*/

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}