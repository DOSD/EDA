#include "diccionario.h"
#include "lista.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};

void sumaBien(const Lista<string>& bien,Diccionario<string,int> &d){
	Lista<string>:: ConstIterator i = bien.cbegin();
	Lista<string>:: ConstIterator f = bien.cend();
	while(i != f){
		if(!d.contiene(i.elem()))
			d.inserta(i.elem(),1);
		else
			d.inserta(i.elem(),d.valorPara(i.elem())+1);
		i.next();
	}
}

void restaMal(const Lista<string>& mal,Diccionario<string,int> &d){
	Lista<string>:: ConstIterator i = mal.cbegin();
	Lista<string>:: ConstIterator f = mal.cend();
	while(i != f){
		if(!d.contiene(i.elem()))
			d.inserta(i.elem(),-1);
		else
			d.inserta(i.elem(),d.valorPara(i.elem())-1);
		i.next();
	}
}

void generaListado(const Diccionario<string,int> &d, Lista<Puntuacion>& listado){
	Diccionario<string,int>::ConstIterator i = d.cbegin();
	Diccionario<string,int>::ConstIterator f = d.cend();
	while (i != f){
		Puntuacion notaFinal = Puntuacion(i.clave(),i.valor());
		if(notaFinal.nota != 0)
			listado.pon_final(notaFinal);
		i.next();
	}

}
void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	  // A IMPLEMENTAR
	Diccionario<string,int> resultados;
	sumaBien(bien,resultados);
	restaMal(mal,resultados);
	generaListado(resultados,listado);
}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}