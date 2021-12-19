#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626
#define INF 0x3f

/**

Solucion:

Para la solucion de este problema, se usa la implemetacion del problema Shortest Routes I, donde
se usa un priorityQueue para determinar el minimo coste entre nodos. Luego se usan dos grafos y 
dos salidas de coste minimo (distancias 1 y 2), esto para poder maximizar la suma al final

Entonces, el grafo 1 (principal), cumple con la entrada de aristas (desde el nodo A al nodo B), 
sin embargo, el grafo 2, cumple con la entrada pero adyacente (desde el nodo B al nodo A); esto
se hace para poder procesar los costes de ida y vuelta.

Finalmente, para poder maximizar el coste, se busca la menor suma entre:
	+ coste actual o principal (dist1[x])
	+ coste en dist2[y], recorriendo todo el grafo principal
	+ coste recorriendo el grafo principal

*/

const int maxN=1e5;//maximo tamaño
int n, m;
vector<array<ll, 2>> grafo1[maxN], grafo2[maxN];//representacion de grafo con un array
ll dist1[maxN], dist2[maxN];//costes de ida y vuelta minimos

void process(int k, vector<array<ll, 2>> grafo[maxN], ll dist[maxN]){
	/**
	 * Metodo process: procesa el coste minimo de un grafo empezando en k y almacena la info en dist
	 * Atributos:
	 * 		k     -> donde empieza
	 * 		grafo -> data principal del grafo a trabajar
	 * 		dist  -> donde se almacenara el coste minimo
	 */
	memset(dist, INF, sizeof(dist1));//inizilizando con INF a dist

	dist[k]=0;//inicializando con coste 0

	//priority queue mediante menores pesos por aristas
	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
	pq.push({0, k});//empieza por el primer nodo {peso 0, nodo 0}

	while(!pq.empty()){//siempre que haya datos en el pq
		array<ll, 2> actual = pq.top();//el con mas prioridad
		pq.pop();

		if(actual[0]<=dist[actual[1]]){//meneja los INF

			//se recorren los hijos o aristas relacionadas
			for(array<ll,2> list : grafo[actual[1]]){

				//se se puede optimizar el coste que ya estaba
				if(dist[list[1]]>actual[0]+list[0]){
					dist[list[1]]=actual[0]+list[0];//se actualiza la distancia
					pq.push({dist[list[1]], list[1]});//se coloca en el pq dicho nodo a procesar
				}
			}
		}
	}
}


int main(){

	cin>>n>>m;//entrada para datos n y m

	for(int i=0;i<m;i++){//entrada de datos para aristas
		ll a, b, value;
		cin>>a>>b>>value;

		grafo1[a-1].push_back({value, b-1});//grafo de ida 
		grafo2[b-1].push_back({value, a-1});//grafo de vuelta
	}

	process(0, grafo1, dist1);//procesa de ida
	process(n-1, grafo2, dist2);//procesa de vuelta

	ll ans=1e18;
	for(int i=0;i<n;i++){//recorre todas los pesos minimos en la principal(dist1)
		for(array<ll, 2> list:grafo1[i]){//recorre en todas las aristas en i
			ans=min(ans, dist1[i]+dist2[list[1]]+list[0]/2);//minimiza el costo
		}
	}
	cout<<ans<<endl;

	return 0;
}
