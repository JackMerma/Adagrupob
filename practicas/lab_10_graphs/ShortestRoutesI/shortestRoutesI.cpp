#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626
#define INF 0x3f

const int maxN=1e5;
int n, m;
vector<array<ll, 2>> grafo[maxN];
ll dist[maxN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin>>n>>m;


	for(int i=0;i<m;i++){
		int a, b, value;
		cin>>a>>b>>value;

		grafo[a-1].push_back({value, b-1});
	}

	memset(dist, INF, sizeof(dist));
	dist[0]=0;

	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
	pq.push({0,0});

	while(!pq.empty()){
		array<ll, 2> actual = pq.top();
		pq.pop();

		if(actual[0]<=dist[actual[1]]){
			for(array<ll,2> list : grafo[actual[1]]){
				if(dist[list[1]]>actual[0]+list[0]){
					dist[list[1]]=actual[0]+list[0];
					pq.push({dist[list[1]], list[1]});
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<dist[i]<<" ";
	cout<<endl;

	return 0;
}
