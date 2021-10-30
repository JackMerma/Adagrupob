/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 29/10/2021
* @filename    : pick_resume
* @description : Algoritmo que devuelve un valor de un arreglo en una posicion especial de esta 
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

/*
 * Complejidad --> O(log2(n))
 *
 * Explicacion: En este caso, solamente se juega con los limites (a y b), donde segun el valor de 'top'
 *              cambian su valor, pero estos disminuyen a la mitad de la longitud que va quedando en
 *              el arreglo, entonces esto quiere decir que van visitando 'mitades' del arreglo.
 *
 *              Por ende, el resultado para encontrar a esa mitad unica(cuando la longitud es 1), se
 *              encuentra luego de log2(n) busquedas.
 *
 */
int pick_resume(int arr[],int len){

	bool top=true;//top
	int a=0,b=len-1;//limites
	
	while(a<b){
		if(top){
			a+=len/2;
			top=false;
		}else{
			b-=len/2;
			top=true;
		}
		len=b+1-a;//cambio de la longitud por una verdadera luego de las operaciones
	}

	return arr[a];//a y b son iguales --> se puede retornar en cualquiera de las dos posiciones

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//entrada de datos
	int n; cin>>n;

	int arr[n]={0};
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int ans=pick_resume(arr,n);

	cout<<"answer:"<<ans<<endl;

	return 0;
}

