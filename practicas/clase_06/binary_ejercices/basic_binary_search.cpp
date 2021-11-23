/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : basic_binary_search
* @description : Busqueda binaria de un numero en un arreglo (con entrada de datos)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

int search(int *arr,int len,int num){
	/**
	 * Metodo search: busqueda binaria de un elemento en un arreglo
	 * Atributos:
	 * 	*arr -> arreglo principal
	 * 	len  -> longitud del arreglo
	 * 	num  -> numero a buscar en el arreglo
	 */
	int a=0,b=len-1;

	//buscando
	while(a<=b){
		int middle=(a+b)/2;

		if(arr[middle]==num) return middle;//si lo encuentra, devuelve la posicion

		if(arr[middle]>num){
			b=middle-1;
		}else{
			a=middle+1;
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

	int arr1[5]={1,2,3,4,5};
	int arr2[10]={0,4,4,4,5,7,8,10,14,15};
	int arr3[7]={3,3,4,4,5,5,7};
	//llamado a la funcion
	
	//posicion de 0 a n-1
	cout<<"resultado "<<search(arr1,5,4)<<endl;
	cout<<"resultado "<<search(arr2,10,11)<<endl;
	cout<<"resultado "<<search(arr3,7,1)<<endl;

	return 0;
}

