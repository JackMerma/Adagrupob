/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 17/11/2021
* @filename    : interview_wait
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

void init_code(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

//prototipo
void interview_wait_time(int*, int);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init_code();
	
	int case1[5]={4,-1,5,2,3};
	interview_wait_time(case1,5);

	int case2[6]={1,-1,5,10,30,40};
	interview_wait_time(case2,6);

	return 0;
}

void interview_wait_time(int times[], int len){
	deque<int> deque_times;

	//llenando deque
	for(int i=0;i<len;i++) deque_times.push_back(times[i]);

	//algoritmo de busqueda de tiempo
	int ans=0;
	while(!deque_times.empty()){
		if(deque_times.back()==-1 || deque_times.front()==-1)
			break;

		if(deque_times.back()<deque_times.front()){
			ans+=deque_times.back();
			deque_times.pop_back();
		}else{
			ans+=deque_times.front();
			deque_times.pop_front();
		}
	}

	//imprimiendo resultado
	cout<<"salida: "<<ans<<endl;
}
