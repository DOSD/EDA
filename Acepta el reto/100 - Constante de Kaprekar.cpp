#include <iostream>

using namespace std;

bool digitos(int num){
	bool distintos = true;
	int a[4],i,numero=num;
	
	for(i=0;i<4;i++){
		a[i]=numero%10;
		numero=numero/10;
	}
	
	if(a[0]==a[1] && a[0]==a[2] && a[0]==a[3])
		distintos=false;
	
	return distintos;
}

int mayor_menor(int num){
	int resultado,i,j,Temp,numero=num;
	int a[4];
	
	for(i=0;i<4;i++){
		a[i]=numero%10;
		numero=numero/10;
	}
	
	
	for(int i=0;i<4;i++) 
		for(int j=0;j<4-1;j++) 
			if(a[j]<a[j+1]){
				Temp=a[j]; 
				a[j]=a[j+1]; 
				a[j+1]=Temp;
			} 
	resultado = a[0]*1000+a[1]*100+a[2]*10+a[3];
	
	return resultado;
}

int menor_mayor(int num){
	int resultado,i,j,Temp,numero=num;
	int a[4];
	
	
	for(i=0;i<4;i++){
		a[i]=numero%10;
		numero=numero/10;
	}
	
	
	for(int i=0;i<4;i++) 
		for(int j=0;j<4-1;j++) 
			if(a[j]>a[j+1]){
				Temp=a[j]; 
				a[j]=a[j+1]; 
				a[j+1]=Temp;
			} 
	resultado = a[0]*1000+a[1]*100+a[2]*10+a[3];
	
	
	
	return resultado;
}

int iteraciones(int num){
	
	int num_iteraciones=0;
	int numero=num;
	if(digitos(num))
		while(numero != 6174 && num_iteraciones <= 7){
			numero= mayor_menor(numero) - menor_mayor(numero);
			num_iteraciones++;
		}
	else num_iteraciones=8;
	
	
	return num_iteraciones;
}

int main(){
	
	int n,i;
	cin>>n;
	
	for(i=0;i<n;i++){
		int entero;
		cin>>entero;
		cout<<iteraciones(entero)<<"\n";
	}
	return 0;
}
