#include <iostream>

using namespace std;

const int  N = 10000;


//{Pre: 0 <= n <= 10000}
int resultado(int a[],int n){
	int cont_impar = 0;
	int cont = 0;
	int cont_par = 0;
	bool impar_en_medio = false;
	while(cont < n && !impar_en_medio){
		if(a[cont]%2 != 0)
			cont_impar++;
		else{
			cont_par++;
			if(cont_impar != 0)
				impar_en_medio = true;
		}
		cont++;	
	}
	
	if(impar_en_medio)
		cont_par = -1;
	
	return cont_par;
}

// {Post: }

int main() {
	
	int n,m,a[N];
	
	cin>>n;
	
	for(int i = 1; i <= n; i++){
		cin >> m;
		
		for(int i = 0; i < m; i++)
			cin>>a[i];
		
		int res = resultado(a,m);
		if(res == -1)
			cout << "NO" <<endl;
		else cout<< "SI " << res<<endl;
	}
	
	
	return 0;
}

