/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 29/10/2021
* @filename    : question010_
* @description : Respondiendo a:
*
*      Q10: What is the time complexity of
*      for (i = 0; i < n; i++) {
*        statement;
*      }
*
*      for (j = 0; j < n; j++) {
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

	int n,ans=0;
	cin>>n;

	for(int i=0;i<n;i++)
		ans++;
	for(int i=0;i<n;i++)
		ans++;

	cout<<"2*"<<n<<"="<<ans<<endl;

	/*
	 * Complejidad del algoritmo --> lineal --> O(n)
	 * 
	 * Explicacion: Recorre un bucle '2n' veces 
	 *              --> esto ya que repite otra vez un bucle ya definido de [0 a n-1] -> [1 a n]
	 *              --> Entonces, el coste será de 2*n veces
	 */

	return 0;
}

