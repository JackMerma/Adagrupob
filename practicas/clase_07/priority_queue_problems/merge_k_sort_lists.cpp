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

void init_code(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

template<typename T>
void print_queue(T que){
	while(!que.empty()){
		cout<<que.top()<<" ";
		que.pop();
	}
	cout<<endl;
}
void merge_sort(vvi data);


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init_code();

	vvi mat_1={{1,4,5},{1,3,4},{2,6}};
	merge_sort(mat_1);

	return 0;
}

void merge_sort(vvi data){
	priority_queue<int, vector<int>, greater<int>> principal_queue;
	
	for(int i=0;i<data.size();i++){
		for(int u=0;u<data[i].size();u++){
			principal_queue.push(data[i][u]);
		}
	}
	print_queue(principal_queue);
}
