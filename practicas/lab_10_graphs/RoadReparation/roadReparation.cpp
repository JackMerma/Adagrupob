#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

vector<int> path(1e5+1, -1);// path o grupos formados

struct arista{
	/**
	 * Estructura Arista
	 */
	int first;	// nodo A
	int second;	// nodo B
	ll value;	// coste entre A y B
};

bool by_value(arista a, arista b){
	/**
	 * Metodo by_value: manera de realizar comparaciones en el sort
	 * Atributos:
	 * 		a -> arista A
	 * 		b -> arista B
	 */
	return a.value < b.value;//de ordena por valor 
}


int search(int node){
	/**
	 * Metodo search: busca al subgrupo de un nodo
	 * Atributos:
	 * 		node -> nodo a buscar su subgrupo
	*/
	if(path[node]==-1){// el mismo es el subgrupo
		return node;
	}

	int father = search(path[node]);// busca el subgrupo de su padre
	path[node] = father; // su subgrupo es el de su padre
	return father; // retorna el grupo general o del padre
}


bool connect(int node_a, int node_b){
	/**
	 * Metodo connect: relaciona al nodo A y B, si sus padres
	 * 				no estan relacionados, entonces, relaciona
	 * 				a A como perterneciente al grupo B
	 * Atributos: 
	 * 		node_a: nodo A a relacionar
	 * 		node_b: nodo B a relacionar
	 */

	int relation_a = search(node_a);//se busca al subgrupo de A
	int relation_b = search(node_b);//se busca al subgrupo de B

	//si pertenecen al mismo subgrupo, entonces no se pueden juntar
	if(relation_b == relation_a){
		return false;
	}

	//el nodo A, pertenece al grupo B
	path[relation_a] = relation_b;
	return true;//si se puede relacionar
}


int main(){
	/**
	 * 	Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin>>n>>m;// entrada de n y m

	vector<arista> aristas;//vector pricipal de aristas

	//entrada de datos para las aristas
	for(int i=0;i<m;i++){
		arista temp;
		cin>>temp.first>>temp.second>>temp.value;
		aristas.push_back(temp);
	}

	//ordenamiento con la logica by_value
	//para obtener las aristas de menor peso
	sort(aristas.begin(), aristas.end(), by_value);


	ll ans=0;//respuesta
	int ar_count=0;//conteo de aristas

	//recorriendo todas las aristas
	for(int i=0;i<m;i++){

		//si conecta los nodos A y B de una arista
		if(connect(aristas[i].first, aristas[i].second)){
			ar_count++;//se aumenta conteo de aristas
			ans+=aristas[i].value;//se suma el valor
		}
	}

	//aristas igual a aristas de arbol de espansion minima
	if(ar_count==n-1)
		cout<<ans<<endl;
	else//si no tiene esa cantidad
		cout<<"IMPOSSIBLE"<<endl;


	return 0;
}
