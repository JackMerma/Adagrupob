/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 29/10/2021
* @filename    : question11_
* @description : Respondiendo a:
*
*      Q11: What is the time complexity of
*      p=0
*      for (i = 1; i < n; i = i * 2) {
*        p++;
*      }
*
*      for (j = 1; j < p; j = j * 2) {
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

	int p=0;
	//se modifica '<=' por el error de conteo y se le resta a cada contado (p-- y ans--) por ese mismo error
	for(int i=1;i<=n;i*=2){
		p++;
	}
	p--;
	for(int i=1;i<=p;i*=2){
		ans++;
	}

	ans--;
	cout<<"log2(log2("<<n<<"))="<<ans<<endl;
	
	/*
	 * Complejidad del algoritmo --> O(log2(log2(n)))
	 * 
	 * Explicacion: Recorre 2 bucles donde el primero depende de 'n' y el segundo de 'p' 
	 * 							--> Si en el primero hay un tiempo logaritmico, eso quiere decir que:
	 * 									p = log2(n)
	 *              --> Luego, en el segundo tambien hay un tiempo logaritmico, para lo cual:
	 *              		m = log2(p)
	 *              --> Entonces, el coste será log2(log2(n)) veces
	 */

	return 0;
}

