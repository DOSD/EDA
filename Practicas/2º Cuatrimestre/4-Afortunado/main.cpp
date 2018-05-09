#include <iostream>
#include "Cola.h"

using namespace std;

unsigned int afortunado(unsigned int n, unsigned int m) { //n>=1  m>=2 
      // A IMPLEMENTAR
	Cola<int> cola;
	
	for(int i = 1; i <= n ; ++i)
		cola.pon(i);
	
	//ambos metodos funcionan, el primero es mas sencillo 

	cola.escogeAfortunadoCircular(m);

	//cola.escogeAfortunado(m);

	return cola.primero();
}


int main() {
    int n,m;
	while((cin >> n)) {
	   cin >> m;
       cout << afortunado(n,m) << endl;	   
	}
	return 0;
}