/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : bankQueue
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define li long int
#define endl "\n"
#define PI 3.1415926535897932384626

/**
 * Explanation: 
 * 		Simplemente se crean los tiempos tomados para los 
 * 		n problemas, luego se hace un sort de menor a mayor
 * 		y finalmente se escogen solamente los que se pueden tomar
 * 		o los que se deben tomar. Con ello, se suma todo el tiempo
 * 		tomado % 1 000 000 007 durante las pasadas.
 */


int main(){
	/**
	 * Metodo principal
	*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin>>n>>t;//entra de n y t

	int A,B,C,t0;//entrada de A, B, C y t_0
	cin>>A>>B>>C>>t0;

	vector<li> time_taken;//tiempo que toma cada problema
	time_taken.push_back(t0);//el primero

	//llenando los tiempos tomados en los problemas
	for(int i=1;i<n;i++){
		//el tiempo desde el segundo problema, usa la formula
		time_taken.push_back(((A*time_taken[i-1]+B)%C)+1);
	}

	//se ordena de menor a mayor (menores tiempos tomados)
	sort(time_taken.begin(), time_taken.end());

	int solved=0, all_time_taken_ans=0;
	li all_time_taken=0;

	//se recorre siempre que hayan preguntas
	//y que no se sobrepase el tiempo dado
	for(int i=0;i<n && all_time_taken+time_taken[i]<=t;i++){
		solved++;//cantidad de preguntas resueltas
		all_time_taken_ans=(all_time_taken_ans+all_time_taken+time_taken[i])%1000000007;//total de tiempo tomado con el MOD
		all_time_taken+=time_taken[i];//total de tiempo tomado
	}

	cout<<solved<<" "<<all_time_taken_ans<<endl;

	return 0;
}