/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 17/11/2021
* @filename    : merge_k_sort_lists
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vvi vector<vector<int>>
#define endl "\n"
#define PI 3.1415926535897932384626

template<typename T>
void print_queue(T que){
	/**
	 *  Template para imprimir el priority_queue
	 */
	while(!que.empty()){
		cout<<que.top()<<" ";
		que.pop();
	}
	cout<<endl;
}

//prototipos
void merge_sort(vvi);

int main(){
	/**
	 *  Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vvi mat_1={{1,4,5},{1,3,4},{2,6}};//caso 1
	merge_sort(mat_1);

	vvi mat_2={{1,4,5,7,8,11,12},{3,4,5,6,7,11},{12,12,12,12}};
	merge_sort(mat_2);//caso 2

	vvi mat_3={{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3}};
	merge_sort(mat_3);//caso 3

	return 0;
}

void merge_sort(vvi data){
	/**
	 *  Metodo merge_sort: imprime una lista ordenada del vector 2D enviado
	 */
	priority_queue<int, vector<int>, greater<int>> principal_queue;//priority principal
	
	//algoritmo
	for(int i=0;i<data.size();i++){
		for(int u=0;u<data[i].size();u++){
			principal_queue.push(data[i][u]);//coloca a todos los datos
		}
	}
	print_queue(principal_queue);//llama al metodo para imprimir la lista en el priority_queue
}
