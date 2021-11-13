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

	//entrada de datos
	int cant;cin>>cant;//cantidad de numeros a ingresar
	int arr[cant];

	for(int i=0;i<cant;i++) cin>>arr[i];//entrada de 'n' numeros

	int num;cin>>num;//numero a buscar

	
	//llamado a la funcion
	int pos=search(arr,cant,num);

	if(pos==-1) cout<<"No encontrado"<<endl;
	else cout<<"Encontrado en la posicion: "<<pos+1<<endl;

	return 0;
}

