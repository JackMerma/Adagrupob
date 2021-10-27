/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 27/10/2021
* @filename    : question05_
* @description : Respondiendo a:
*
*      Q5: What is the time complexity of
*      for (i = 0; i < n; i++) {
*        for(j = 0; j < i; j++) {
*          statement
*        }
*      }
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin>>n;


	//algoritmo
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			cout<<'1'<<" ";
		}
		cout<<'0'<<endl;
	}
	

	/*
	 * Complejidad del algoritmo --> cuadratico --> O(n^2)
	 * 
	 * Explicacion: Recorre dos bucles 'n*(n^2 + 1)/2' veces 
	 * 							--> rango: [0 a n-1]*[0 a n-1 en la mitad de veces] = 
	 *
	 * 									1 	2	 3	 4	 5	 ... 	n
	 * 							1   0
	 * 							2   1		0
	 * 							3   1		1	 0
	 * 							4   1		1	 1 	 0
	 * 							5   1		1	 1 	 1	 0
	 * 						 ...
	 * 							n   1   1	 1 	 1   1	 ...  0
	 *
	 * 							=> recorre n*(n^2 + 1)/2' veces
	 *
	 */


	return 0;
}

