/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : sqrt_binary_function
* @description : Programa que imprime la raiz de un numero cuadratico (entrada de datos)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626


int search_root(int number){
	/**
	 * Metodo search_root: devuelve la raiz de un numero (si este la tiene), de lo contrario devuelve -1
	 * Atributos:
	 * 	number -> numero a sacarle la raiz
	 */
	float ans;
	int a=0,b=number;

	while(a<b-1){
		ans=(a+b)/2;
		if(ans*ans==number) return (int)ans;
		if(ans*ans>number){
			b=ans;
		}else{
			a=ans;
		}
	}
	return -1;
}

int main(){
	/**
	 * Metodo principal con entrada de datos
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	cout<<search_root(100)<<endl;
	cout<<search_root(12)<<endl;
	cout<<search_root(121)<<endl;
	cout<<search_root(82)<<endl;


	return 0;
}
