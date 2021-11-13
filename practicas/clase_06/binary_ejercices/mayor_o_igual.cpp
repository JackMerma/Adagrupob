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
	cout<<"dont"<<endl;
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


	//entrada de datos
	int cant;cin>>cant;//cantidad de numeros a ingresar
	int numbers[cant];

	for(int i=0;i<cant;i++) cin>>numbers[i];//ingreso de 'n' datos

	//numero a encontrar o mayor a este
	int found;cin>>found;


	//llamado a la funcion
	int number_searching=search_equal_or_next(numbers,cant,found);

	if(number_searching==-1)
		cout<<"No hay mayor o igual que "<<found<<endl;
	else
		cout<<"Mayor o igual que "<<found<<": "<<number_searching<<endl;

	return 0;
}

