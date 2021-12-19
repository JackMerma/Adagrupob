#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626
#define INF 0x3f

/**

Solucion:

En este problema, basicamente se hace un recorrido BFS, por los nodos, (Dijkstra) pero con menos coste
usando un priorityQueue, entones:

	+ Primero, se insertan los datos en una matriz enlazada que tiene almacena dos datos por cada
	  una de ella (coste y nodo de llegada).
	+ Luego, se desarrolla el algoritmo, donde se busca optimizar el el coste entre A y Z, 
	  suponiendo que entre ambos pudo haberse tomado otras opciones

	+ Finalmente se recorre el arreglo dist que guarda los costes minimos hacia cada nodo 

*/

const int maxN=1e5;//maximo tamaño
int n, m;
vector<array<ll, 2>> grafo[maxN];//representacion de grafo con un array
ll dist[maxN];//distancias minimas

int main(){
	/**
	 * 	Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin>>n>>m; //entrada de datos para n y m


	memset(dist, INF, sizeof(dist));//inicializando arreglo de distancias minimas

	//entrada de datos para las aristas
	for(int i=0;i<m;i++){
		int a, b, value;
		cin>>a>>b>>value;// nodo A, nodo B y valor de la arista

		grafo[a-1].push_back({value, b-1});//agrega un par en la lista [a-1]
	}

	dist[0]=0;//la primera distancia es 0

	//priority queue mediante menores pesos de aristas
	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
	pq.push({0,0});//empieza por el primer nodo {peso 0, nodo 0}

	while(!pq.empty()){//siempre que haya datos en el pq
		array<ll, 2> actual = pq.top();//el con mas prioridad
		pq.pop();

		if(actual[0]==dist[actual[1]]){//para menejar INF 

			//se recorren todos sus hijos (como BFS)
			for(array<ll,2> list : grafo[actual[1]]){

				//si la opcion de la suma es max optima que la que ya estaba
				if(dist[list[1]]>actual[0]+list[0]){
					dist[list[1]]=actual[0]+list[0];//se actualiza la distancia
					pq.push({dist[list[1]], list[1]});//se coloca en el pq dicho nodo a procesar
				}
			}

		}
	}

	//imprimiendo todas las distancias minimas
	for(int i=0;i<n;i++)
		cout<<dist[i]<<" ";
	cout<<endl;

	return 0;
}
