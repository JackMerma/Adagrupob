#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626
#define INF 0x3f

/**

Solucion:

En este problema, se usa un algoritmo hamiltoniano de fuerza bruta, entonces basicamente se hallan
todas las posibles combinaciones de inicio de recorrido; para ello:

	+ Se trabaja con una matriz de adyacencia, donde se introducen los pesos
	+ Luego, se recorren todos los inicios posibles (N posiciones) -> primer bucle (nodo fijo)
	+ Se recorre dentro la matriz N x N, donde se busca optimizar al grafo (matriz de adyacencia)
	  (primer y segundo bucle)
	+ Finalmente, en cada una de las posiciones, estara el peso minimo para ir de A a B.

*/

const int maxN=500;//maxima cantidad
int n, m, q;
ll grafo[maxN][maxN];//grafo principal

int main(){
	/**
	 * 	Metodo principal
	 */

	cin>>n>>m>>q;//entrada de datos para n, m y q
	memset(grafo, INF, sizeof(grafo));//inicializando con INF
	
	//entrada para las aristas
	for(int i=0;i<m;i++){
		ll a, b, value;
		cin>>a>>b>>value;

		//ambos sentidos
		grafo[a-1][b-1]=min(value, grafo[a-1][b-1]);
		grafo[b-1][a-1]=min(value, grafo[b-1][a-1]);
	}

	//algoritmo de fuerza bruta hamiltoniano
	//encuentra todas las posibles relaciones de un nodo fijo (posicion fija)
	//con los demas nodos
	for(int i=0;i<n;i++){//posicion fija

		//recorrido todo el grafo
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(a==b)//no se toma en consideracion
					grafo[a][b]=0;
				else//suma de nodos con relacion al nodo fijo
					grafo[a][b]=min(grafo[a][b], grafo[a][i]+grafo[i][b]);
			}
		}
	}

	//salida de todas las consultas de recorridos
	for(int i=0;i<q;i++){
		int a, b;
		cin>>a>>b;
		//mayor a inf, es inaceptable
		cout<<(grafo[a-1][b-1]<1e18?grafo[a-1][b-1]:-1)<<endl;
	}

	return 0;
}
