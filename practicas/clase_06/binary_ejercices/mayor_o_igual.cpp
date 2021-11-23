/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : mayor_o_igual
* @description : busqueda binaria de un elemento (si existe) o del siguiente (no existe) con entrada de datos
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626


int search_equal_or_next(int *arr,int len,int found){
	/**
	 * Metodo search_equal_or_next: busqueda binaria del elemento siguiente al que se busca
	 * Atributos:
	 * 	*arr -> arreglo principal
	 * 	len  -> longitud del arreglo
	 * 	found  -> numero de referencia a buscar en el arreglo
	 */
	int a=0,b=len-1;
	int middle;

	while(a<=  b){
		middle=(a+b)/2;
		if(arr[middle]==found) return arr[middle];
		
		if(arr[middle]>found){
			b=middle-1;
		}else{
			a=middle+1;
		}
	}
	//la posicion acta
	if(found>arr[len-1]) return -1;//no existe
	return arr[middle+1];//posicion siguiente
}


int main(){
	/**
	 * Metodo principal con entrada de datos
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int arr1[5]={1,2,3,4,5};
	int arr2[11]={0,4,4,4,5,7,8,10,14,15,17};
	int arr3[7]={3,3,4,4,5,5,7};

	cout<<search_equal_or_next(arr1,5,3)<<endl;
	cout<<search_equal_or_next(arr2,11,13)<<endl;
	cout<<search_equal_or_next(arr3,7,100)<<endl;

	return 0;
}

