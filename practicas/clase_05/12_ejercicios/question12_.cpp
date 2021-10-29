/** 
 * @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
 * @created     : 29/10/2021
 * @filename    : question12_
 * @description : Respondiendo a:
 *
 *      Q12: What is the time complexity of
 *      for (i = 0; i < n; i++) {
 *        for (j = 1; j < n; j = j * 2){
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

	int n,ans=0;
	cin>>n;

	for(int i=0;i<n;i++){
		//se le coloca '<=' por el error de conteo y se le resta (ans--) por ese mismo error
		for(int j=1;j<=n;j*=2){
			ans++;
		}
		ans--;
	}

	cout<<n<<"*"<<"log2("<<n<<")="<<ans<<endl;


	/*
	 * Complejidad del algoritmo --> O(n*(log2(n)))
	 * 
	 * Explicacion: Recorre dos bucles (1 anidado)
	 *              --> El primero solo depende de 'n', entonces el coste es 'n'
	 *              --> Luego, el segundo tambien depende de 'n', pero el crecimiento es de log2(n)
	 *
	 *              --> Finalmente, se puede decir que el coste es la multiplicacion => n*log2(n)
	 */


	return 0;
}

