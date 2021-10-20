/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 18/10/2021
* @filename    : suma_de_10
* @description : Determina si en un arreglo, 2 elementos suman 10
*/
#include <bits/stdc++.h>
using namespace std;

//método para saber si dos numeros en el arreglo, suman 10
//recibe un arreglo de numeros 'arr' y su tamaño 'n'
bool sum_ten(int arr[], int n){
	for(int i=0;i<n;i++){//primer sumando
		for(int u=0;u<n;u++){//segundo sumando
			if(i!=u&&arr[i]+arr[u]==10)//Si es diferente posicion y si suma 10
				return true;
		}
	}
	return false;
}

//metodo principal
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//codigo
	//entradad de datos
	int n;//cantidad de elementos 
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)// entradad de 'n' numeros
		cin>>arr[i];

	//algoritmo
	bool case_10=sum_ten(arr,n);//case_10, almacena la respuesta(0|1)
	cout<<((case_10)?"hay suma de 10":"no hay suma de 10");
	return 0;
}

