/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 27/10/2021
* @filename    : question02_
* @description : Respondiendo a:
*
*      Q2: What is the time complexity of
*      for (i = n; i > 0; i--) {
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
	for(int i=n;i>0;i--){
		//statement
		cout<<"hoola!"<<endl;
	}

	/*
	 * Complejidad del algoritmo --> lineal --> O(n)
	 * 
	 * Explicacion: Recorre un bucle 'n' veces --> rango: [n a 1] = [1 a n] = n veces
	 */


	return 0;
}

