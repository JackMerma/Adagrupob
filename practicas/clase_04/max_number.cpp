/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 18/10/2021
* @filename    : max_number
* @description : Encuentra el maximo de una lista de numeros (entradad de datos)
* 							 Linea 1: lee n. Las siguientes n lineas leen 'n' numeros
*/
#include <bits/stdc++.h>
using namespace std;

//metodo para encontrar al maximo
//recibe un arreglo de enteros 'a' y su longitud 'len'
int foundMax(int a[], int len){
	int aux=a[0];//inicializa al maximo en la pos '0' del arreglo => a[0]

	for(int i=1;i<len;i++)//recorre al arreglo desde 1 hasta n-1
		aux=max(aux,a[i]);//el aux almacenará al máximo en caso de encontrarse
	return aux;
}

//Metodo principal
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//codigo
	//entrada de datos
	int n;//n elementos en el arreglo
	cin>>n;
	int arr[n]={0};
	for(int i=0;i<n;i++)//insercion de n datos en el arreglo
		cin>>arr[i];
	
	//algoritmo
	int max=foundMax(arr,n);//variable que almacena al maximo del arreglo

	cout<<"Numero maximo del arreglo: "<<max;

	return 0;
}

