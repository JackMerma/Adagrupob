/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 29/10/2021
* @filename    : question07_
* @description : Respondiendo a:
*
*      Q7: What is the time complexity of
*      for (i = 1; i < n; i = i*2) {
*        statement;
*      }
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;


	//algoritmo
	for(int i=1;i<n;i*=2){
		cout<<"hola!"<<endl;
	}

	/*
	 * Complejidad del algoritmo --> logaritmico --> log2(n)
	 * 
	 * Explicacion: Recorre un bucle log2(n) veces 
	 * 							--> dado que el crecimiento es 1, 2, 4, 8, 16, ... 2^k
	 * 							--> entonces, si debe ser menor que 'n', 'i' recorreria log2(n) veces
	 */

	return 0;
}

