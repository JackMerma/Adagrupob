/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 18/10/2021
* @filename    : sumar_par
* @description : Imprime la suma del dato i-ésimo par del arreglo con todas las posiciones u-ésimas del mismo arreglo
*/
#include <bits/stdc++.h>
using namespace std;

//metodo principal
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//codigo
	//caso de prueba
	int arr[]={7,6,5};//arreglo
	int len=3;//longitud del arreglo

	//algoritmo
	for(int i=0;i<len;i++){//recorre n elementos (0...n-1)
		if(i%2==0){//si el elemento es par 
			for(int u=0;u<len;u++){//recorre n elemento (0...n-1)s
				//imprime la suma del par mas la pos u-ésima del arreglo
				cout<<(arr[u]+arr[i])<<"\n"; 
			}
		}
	}

	return 0;
}

