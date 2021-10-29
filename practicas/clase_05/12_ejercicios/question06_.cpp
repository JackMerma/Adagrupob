/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 27/10/2021
* @filename    : question06_
* @description : Respondiendo a:
*
*      Q6: What is the time complexity of
*      p=0
*      for (i = 1; p <= n; i++) {
*        p = p + i;
*      }
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;cin>>n;

	//algoritmo
	int p=0;
	for(int i=1;p<=n;i++){
		cout<<"hola!"<<endl;
		p+=i;
	}


	/*
	 * Complejidad del algoritmo --> raiz cuadrada --> sqrt(n)
	 * 
	 * Explicacion: Este depende del crecimiento de 'p', el cual crece -> m*(m+1)/2 veces, entonces
	 * 							si debe ser menor o igual que 'n', este proceso se corta cuando:
	 * 							[crecimiento triangular] O(m*(m+1)/2) > n  ==> m^2 > n ==> m > sqrt(n) veces 
	 */


	return 0;
}

