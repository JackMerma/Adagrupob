#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626
#define INF 0x3f

const int maxN=1e5;
int n, m;
vector<array<ll, 2>> grafo1[maxN], grafo2[maxN];
ll dist1[maxN], dist2[maxN];

void process(int k, vector<array<ll, 2>> grafo[maxN], ll dist[maxN]){
	memset(dist, INF, sizeof(dist1));

	dist[k]=0;
	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
	pq.push({0, k});

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
}


int main(){

	cin>>n>>m;

	for(int i=0;i<m;i++){
		ll a, b, value;
		cin>>a>>b>>value;

		grafo1[a-1].push_back({value, b-1});
		grafo2[b-1].push_back({value, a-1});
	}

	process(0, grafo1, dist1);
	process(n-1, grafo2, dist2);

	ll ans=1e18;

	for(int i=0;i<n;i++){
		for(array<ll, 2> list:grafo1[i]){
			ans=min(ans, dist1[i]+dist2[list[1]]+list[0]/2);
		}
	}
	cout<<ans<<endl;

	return 0;
}
