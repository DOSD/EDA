#include <iostream>

using namespace std;

const int N = 10000;


//{Pre: 1<= n <= longituda(a)}
void contarMayorYmenor(long long a[], int n,long long int &menor,long long int &mayor,int &contMenor,int &contMayor){
	contMayor = 1, contMenor = 1;

	mayor = a[0];
	menor = a[0];
	// {I :(1 <= i <= n) ^ (menor = menor(v,n) ^  mayor=mayor(v,n) ^ (contMayor=# j: 1 <= j < i : v[j] = mayor(v,n)) ^ (contMenor= # c: 1 <= c < i : v[c] = mayor(v,n)))}
	for(int i = 1; i < n; i++){
		if (a[i] == mayor)
			contMayor++;
		if(a[i] > mayor){
			mayor = a[i];
			contMayor = 1;
		}
		if(a[i] == menor)
			contMenor++;
		if(a[i] < menor){
			menor = a[i];
			contMenor = 1;
		}
		
	}
}
// menor(v,n) = min i : 0 <= i < n: v[i]
// mayor(v,n) = max i: 0 <= i < n: v[i]
//{Post: menor = menor(v,n) ^  mayor=mayor(v,n) ^ (contMayor=# i: 0 <= i < n : v[i] = mayor(v,n)) ^ (contMenor= # j: 0 <= j < n : v[j] = mayor(v,n)) }

int main() {

	int n,cont,contMenor, contMayor;;
	long long m, menor, mayor; 
	long long  a[N];
	cin>>n;

	for (int i =0; i < n; i++){
		cont = 0;
		cin>>m;
		while(m != 0){
			a[cont] = m;
			cont++;
			cin>>m;
		}
		contarMayorYmenor(a,cont,menor, mayor,contMenor,contMayor);
		cout << menor <<" "<< contMenor<< " "<< mayor<< " "<< contMayor << "\n";
	}
	return 0;
}