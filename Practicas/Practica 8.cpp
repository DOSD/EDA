#include <iostream>
#include <cmath>

using namespace std;

bool ataca(int sol[], int n, int ultima){
	int i = 0;

	while(i < ultima && sol[i] != sol[ultima] && (abs(sol[i] - sol[ultima])) != (abs(i - ultima)))//!mismaFila(sol[i],sol[iltima]) && !mismaDiagonal(sol[i],sol[ultima])
		++i;
	return i != ultima;
}

bool atacaT(int sol[], int n, int ultima){
	int i = 0;
	while(i < ultima && sol[i] != sol[ultima] )//!mismaFila(sol[i],sol[iltima]) && !mismaDiagonal(sol[i],sol[ultima])
		++i;
	return i != ultima;
}

bool esAtacado(int sol[], int ultima,int aux[]){
	int i = 0;
	while(i < ultima && ((abs(sol[i] - sol[ultima])) != (abs(i - ultima)) || aux[i] == 0))//!mismaFila(sol[i],sol[iltima]) && !mismaDiagonal(sol[i],sol[ultima])
		++i;
	return i != ultima;
}

int coloca(int sol[],int n, int k, int reinas, int torres,int aux[]){
	if (n == k){
		//caso base
		/*for(int i = 0; i < n; ++i)
			cout<<sol[i];
		cout<<endl;
		*/
		return 1;
	}
	int ret = 0;
	for(int i = 0; i < n; ++i){
		sol[k] = i;
		if(torres > 0)
			if(!atacaT(sol, n, k)){
				aux[k] = 0;
				if(!esAtacado(sol,k,aux))
					ret += coloca(sol, n, k + 1,reinas,torres-1,aux);
			}
		if(reinas > 0)
			if(!ataca(sol, n, k)){
				aux[k] = 1;
				ret += coloca(sol, n, k + 1,reinas-1,torres,aux);
			}
	}
	return ret;
}

int main(){
	int t,r,sol;
	int filas[9];
	int aux[9];
	while (cin >> t >> r && (t != 0 || r != 0 )){
		cout<<coloca(filas,t+r,0,r,t,aux)<< endl;
	}
	return 0;
}