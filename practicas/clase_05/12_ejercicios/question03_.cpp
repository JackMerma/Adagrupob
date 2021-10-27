/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 27/10/2021
* @filename    : question03_
* @description : Respondiendo a:
*
*      Q3: What is the time complexity of
*      for (i = 0; i < n; i=i+5) {
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
	for(int i=0;i<n;i+=5){
		cout<<"hola!"<<endl;
	}
	
	/*
	 * Complejidad del algoritmo --> lineal --> O(n)
	 * 
	 * Explicacion: Recorre un bucle 'n/5' veces aproximadamente 
	 * 							--> rango: [0 a n-1] de 5 en 5 = [1 a n]/5 = n/5 veces
	 */
	

	return 0;
}

