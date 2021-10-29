/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 27/10/2021
* @filename    : question04_
* @description : Respondiendo a:
*
*      Q4: What is the time complexity of
*      for (i = 0; i < n; i++) {
*      	 for (j = 0; j < n; j++) {
*       	 statement;
*      	 }
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
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"hola!"<<endl;
		}
	}

	/*
	 * Complejidad del algoritmo --> cuadratico --> O(n^2)
	 * 
	 * Explicacion: Recorre dos bucles 'n^2' veces 
	 * 							--> rango: [0 a n-1]*[0 a n-1] = [1 a n]*[1 a n] = n*n = n^2 veces
	 */


	return 0;
}

