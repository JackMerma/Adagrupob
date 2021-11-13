/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : menor_elemento_arreglo_rotado
* @description : Encuentra al valor minimo de un arreglo ordenado pero rotado (con entrada de datos)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

int searchRotatedArr(int *arr, int len){
	/**
	 * Metodo searchRotateArr: busca al menor elemento de un arreglo rotado
	 * Atributos:
	 * 	*arr -> arreglo principal
	 * 	len  -> longitud del arreglo
	 */
	int a=0,b=len-1,m=(a+b)/2;

	while(a<b){
		//cout<<a<<"<"<<m<<">"<<b<<": "<<arr[m]<<endl;
		if(arr[m]<arr[0]){//si arr[m] es menor, quiere decir que se a podido rotar y el menor este a la izquierda
			b=m;
		}else{//de lo contrario se a podido rotar pero sigue en la derecha 
			a=m+1;
		}
		m=(a+b)/2;
	}
	return min(arr[m],arr[0]);//si esta ordenado
}

int main(){
	/**
	 * Metodo principal con entrada de datos
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	//entrada de datos
	int cant;cin>>cant;//cantidad de datos
	int arr[cant];

	for(int i=0;i<cant;i++) cin>>arr[i];//entrada de 'n' datos


	//llamado a la funcion
	int minElemento=searchRotatedArr(arr,cant);
	cout<<"Minimo encontrado:"<<minElemento<<endl;

	return 0;
}

