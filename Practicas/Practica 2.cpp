#include <iostream>

using namespace std;

// Usar esta función para la práctica
//{Pre: 0 <= n <= longitud(v)}
/*
bool resuelve(long long int a[],long long int n){
	bool ret , creciente = true, decreciente = true;
	long long int i = 0;
	while(i < n-1 && (creciente || decreciente)){
		if(creciente && !(a[i] < a[i+1]))
			creciente = false;
		if(decreciente && !(a[i] > a[i+1]))
			decreciente = false;
		i++;
	}

	if(creciente || decreciente)
		ret = true;
	else ret = false;
	return ret;
}
//{Pos: ret = P.t i: 0 < i < n-1 : v[i] < v[i+1] v P.t j: 0 < j < n-1 :  v[j] > v[j+1]}
//{I: ( 0 <= i <= n-1)^(ret = P.t j:  0 < j <= i : v[j] < v[j+1] v P.t c:  0 < c <= i : v[c] > v[c+1] )

*/
//Usar ésta para Acepta el reto 
void resuelve(long long int n){
	long long int a,b;
		bool ret , creciente = true, decreciente = true;
		long long int i = 1;

		cin>>a;
		while(i < n && (creciente || decreciente)){
			
			cin>>b;
			if(creciente && !(a < b))
				creciente = false;
			if(decreciente && !(a > b))
				decreciente = false;
			i++;
			a=b;

		}
		if(creciente || decreciente)
			cout<<"DALTON"<<endl;
		else cout<<"DESCONOCIDOS"<<endl;
		cin.ignore(256,'\n');
}

int main(){
	long long int n;
	
	
	cin>>n;

	while(n != 0 && cin){
		
		resuelve(n);
		
		cin>>n;


	}



	return 0;
}
