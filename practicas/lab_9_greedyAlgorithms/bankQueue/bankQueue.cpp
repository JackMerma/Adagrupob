/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : bankQueue
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

/**
 * Explanation: 
 * 		Primero, e ordenan las opciones que hay priorizando el dinero
 * 		y luego el tiempo que toman, de mayor a menor; luego, como ya
 * 		se tiene un orden maximizado, simplemente si en la posicion maxima
 * 		que puede esperar (tiempo), esta vacío, simplemente se inserta, 
 * 		si no es asi, entonces se debe buscar una posicion o tiempo vacío
 * 		desde su limite de tiempo hasta 0, finalmente, si ya no hay mas cupos
 * 		o espacios para llenar, simplemente la suma de todo ello (dinero),
 * 		sobre el tiempo que se peude atender, es la respuesta maxima de ganancia.
*/



int best_comparation(pair<int,int> a, pair<int,int> b){
	/* 
		Metodo best_comparation:
	    Descropcion: Realiza la mejor comparacion tomando como mas
	   				relevante Money que Time, es decir, si Money de
	   				ambas obciones son iguales, entonces el que
	   				demande menos tiempo, tendra prioridad; de lo
	   				contrario, el que tenga mas dinero, tendra mas
	   				prioridad
	    Atributos:
	   				a -> primera opcion 
	   				b -> segunda opcion
	 */

	//first es Money y second es Time
	if(a.first==b.first)//si ofrecen el mismo dinero
		return a.second > b.second;//el que pueda esperar mas
	return a.first > b.first;//el que tenga mas dinero
}

int main(){
	/* 
		Metodo principal
	*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin>>n>>t;//entrada para n y t

	//Se crea un vector de pares, donde el pair representa
	//cada opcion que se ofrece, donde first es para Money
	//y second para Time
	vector<pair<int,int>> options(n, pair<int,int>(0,0));

	for(int i=0;i<n;i++)
		cin>>options[i].first>>options[i].second;//entrada de opciones

	//se realiza un sort, para tener las mejores opciones al inicio
	sort(options.begin(), options.end(), best_comparation);


	int ans=0;//respuesta
	int best_option[50]={0};//las opciones finales (tamaño 48 -> 50 para no tener errores)

	for(int i=0;i<n;i++){//se recorre todas las opciones, si ya esta ocupada, entonces se recorre hasta el inicio
		for(int u=options[i].second; u>=0; u--){//se recorre desde la posicion de su Time (idear el caso real)
			if(best_option[u]==0){//si hay posicion libre
				best_option[u]=options[i].first;//se acumula
				ans+=options[i].first;//se añade a la respuesta
				break;//se finaliza
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}