/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 29/10/2021
* @filename    : question08_
* @description : Respondiendo a:
*
*      Q8: What is the time complexity of
*      for (i = n; i >= 1; i = i/2) {
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

	int n,result=0;//result almacena la respuesta de un logaritmo en base 2
	cin>>n;

	for(int i=n;i>=1;i/=2)
		result++;

	cout<<"log2("<<n<<")="<<result-1<<endl;//se le resta 1 por la verificacion del for (>=1) 


	/*
	 * Complejidad del algoritmo --> algoritmico --> O(log2(n))
	 * 
	 * Explicacion: Recorre un bucle log2(n) veces 
	 * 							--> dado que el crecimiento es n, n/2, n/4, n/8, ... n/2^k
	 * 							--> luego, si n es $n se recorre $m
	 * 							    $n    -     $m
	 * 							     2    -     1
	 * 							     4    -     2
	 * 							     8    -     3
	 * 							     16   -     4
	 *
	 * 							     ...  -     ...
	 *
	 * 							     2^k  -     log2(n)
	 * 							--> entonces, si debe ser mayor o igual que 1, 'i' recorreria log2(n) veces
	 */
	

	return 0;
}

