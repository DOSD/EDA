
#include <iostream>

#define ll long long

using namespace std;
 
const int cons = 46337;

void multiply(ll F[2][2], ll M[2][2])
{
    ll x =  (F[0][0] * M[0][0] + F[0][1] * M[1][0])%cons;
    ll y =  (F[0][0] * M[0][1] + F[0][1] * M[1][1])%cons;
    ll z =  (F[1][0] * M[0][0] + F[1][1] * M[1][0])%cons;
    ll w =  (F[1][0] * M[0][1] + F[1][1] * M[1][1])%cons;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
void power(ll F[2][2], long long n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1,1},{1,0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}
 

ll fibo_matrix(ll n)
{
    ll F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

int main()
{
    long long n;
    	while(cin>>n && n != 0)
			cout<<fibo_matrix(n)<<endl;
  
    return 0;
}