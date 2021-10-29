/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 29/10/2021
* @filename    : question09_
* @description : Respondiendo a:
*
*      Q9: What is the time complexity of
*      for (i = 0; i * i < n; i++) 
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

	for(int i=0;i*i<n;i++)
		ans++;

	cout<<"sqrt("<<n<<")="<<ans<<endl;

	/*
	 * Complejidad del algoritmo --> raiz cuadrada --> O(sqrt(n))
	 * 
	 * Explicacion: Recorre un bucle sqrt(n) veces 
	 * 							--> dado que el crecimiento es 0, 1, 4, 9, 16, i^k
	 * 							--> luego, si n es $n se recorre $m, dando resultado a $ans
	 * 							    $n    -     $m                   =     $ans
	 * 							     0    -     0          					 =       0
	 * 							     1    -     0,1       					 =       1
	 * 							     4    -     0,1,2      					 =       2
	 * 							     9    -     0,1,2,3              =       3
	 * 							     16   -     0,1,2,3,4            =       4
	 *
	 * 							    ...   -       ...                =      ...
	 * 							    
	 * 							     n    -     0,1,2,3,... sqrt(n)  =    sqrt(n)
	 * 							--> entonces, recorreria sqrt(n) veces
	 */

	return 0;
}

