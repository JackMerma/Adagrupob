/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 18/10/2021
* @filename    : sumar_par
* @description : Imprime la suma del dato i-ésimo par del arreglo con todas las posiciones del mismo arreglo
*/
#include <bits/stdc++.h>
using namespace std;

//metodo principal
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//codigo
	//entrada de datos
	int n;
	cin>>n;
	int arr[n]={0};

	for(int i=0;i<n;i++)
		cin>>arr[i];

	//algoritmo
	for(int i=0;i<n;i++){//recorre n elementos (0...n-1)
		if(arr[i]%2==0){//si el elemento es par 
			for(int u=0;u<n;u++){//recorre n elemento (0...n-1)s
				//imprime la suma del par mas la pos u-ésima del arreglo
				cout<<arr[i]<<"+"<<arr[u]<<"="<<(arr[u]+arr[i])<<"\n"; 
			}
		}
	}

	return 0;
}

