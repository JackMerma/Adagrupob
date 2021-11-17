/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 17/11/2021
* @filename    : interview_wait
* @description : Encuentra el menor tiempo de espera en una entrevista
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

//prototipo
void interview_wait_time(int*, int);

int main(){
	/**
	 *  Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int case1[5]={4,-1,5,2,3};
	interview_wait_time(case1,5);

	int case2[6]={1,-1,5,10,30,40};
	interview_wait_time(case2,6);

	int case3[10]={10,8,6,4,2,-1,3,5,7,9};
	interview_wait_time(case3,10);

	return 0;
}

void interview_wait_time(int times[], int len){
	/**
	 *  Metodo interview_wait_time: imprime el tiempo de espera
	 *  Atributos:
	 *  	times -> arreglo de tiempos
	 *  	len   -> longitud del arreglo
	 */
	deque<int> deque_times;//deque principal

	//llenando deque
	for(int i=0;i<len;i++) deque_times.push_back(times[i]);

	//algoritmo de busqueda de tiempo
	int ans=0;
	while(!deque_times.empty()){
		if(deque_times.back()==-1 || deque_times.front()==-1)//si se llega al objetivo -> termina
			break;

		if(deque_times.back()<deque_times.front()){//si el ultimo es menor, toma el ultimo
			ans+=deque_times.back();
			deque_times.pop_back();
		}else{//de lo contrario toma el primero
			ans+=deque_times.front();
			deque_times.pop_front();
		}
	}

	//imprimiendo resultado
	cout<<"salida: "<<ans<<endl;
}
