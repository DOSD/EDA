#include <iostream>

using namespace std;
// {PRE: 0 <= n <= longitud(v)}
int resuelve(int a[], int n){
	int ret=-1,cont = 0, temp= 0;
	// {I: (0 <= i < n) ^ (max P.T a,b: 0 <= a < b < i : (Ex i,j: a <= i < j <= b : v[i] = v[j]): b - a -1 )}
	while(cont < n-1){
		if(a[cont] == a[cont+1]){
			temp++;
			if(temp>ret)
				ret = temp;
		}
		else temp = 0;
		cont++;
	}
	return ret;
}
//{POST: ret = max P.T a,b: 0 <= a < b < n : (Ex i,j: a <= i < j <= b : v[i] = v[j]): b - a -1 }
//poscondicion corregida
//iguales(v,a,b) = P.t i : a<= i <= b: v[i]= v[a]
//{Post: ret = max a,b: (0 <= a <= a < n )^iguales(v,a,b): b-a+1  }

int main(){
	int n,b,a[100000],cont; 
	int res;

	cin >> n;

	while (n != -1){
		a[0]  = n;
		cont = 1;
		cin >> b;
		while(b != -1){
			a[cont]=b;
			cont++;
			cin>>b;
		}
		res= resuelve(a,cont);
		if(res == -1)
			cout<< "HOY NO COMEN"<<endl;
		else cout << res<< endl;
		cin>>n;
	}


	return 0;
}