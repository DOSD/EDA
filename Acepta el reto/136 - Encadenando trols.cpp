#include <iostream>

using namespace std;

int numCortes(int fuerza,int longitud){
	
	if(longitud <= 2*fuerza)
		return 0;
	
	int ladoCorto = longitud/3 ;
	int ladoLargo = longitud - ladoCorto;

	int res1 = numCortes(fuerza,ladoCorto);
	int res2 = numCortes(fuerza,ladoLargo);

	return 1 + res1 + res2;

}

int main(){
	int n,m;
	cin>>n;

	while(n != 0){
		cin>>m;
		cout<<numCortes(n,m)<<endl;
		cin>>n;
	}

	return 0;
}