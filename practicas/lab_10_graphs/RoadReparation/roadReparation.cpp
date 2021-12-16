#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

vector<int> path(1e5+1, -1);

struct arista{
	int first;
	int second;
	ll value;	
};

bool by_value(arista a, arista b){
	return a.value < b.value;
}


int search(int node){
	if(path[node]==-1){
		return node;
	}

	int father = search(path[node]);
	path[node] = father; 
	return father; 
}


bool connect(int node_a, int node_b){

	int relation_a = search(node_a);
	int relation_b = search(node_b);

	if(relation_b == relation_a){
		return false;
	}

	
	path[relation_a] = relation_b;
	return true;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;

	cin>>n>>m;
	vector<arista> aristas;

	for(int i=0;i<m;i++){
		arista temp;
		cin>>temp.first>>temp.second>>temp.value;
		aristas.push_back(temp);
	}

	sort(aristas.begin(), aristas.end(), by_value);


	ll ans=0;
	int ar_count=0;

	for(int i=0;i<m;i++){
		if(connect(aristas[i].first, aristas[i].second)){
			ar_count++;
			ans+=aristas[i].value;
		}
	}


	if(ar_count==n-1)
		cout<<ans<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;


	return 0;
}
