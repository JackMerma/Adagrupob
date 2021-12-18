#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626
#define INF 0x3f

const int maxN=500;
int n, m, q;
ll grafo[maxN][maxN];

int main(){

	cin>>n>>m>>q;
	memset(grafo, INF, sizeof(grafo));
	
	for(int i=0;i<m;i++){
		ll a, b, value;
		cin>>a>>b>>value;
		grafo[a-1][b-1]=min(value, grafo[a-1][b-1]);
		grafo[b-1][a-1]=min(value, grafo[b-1][a-1]);
	}

	for(int i=0;i<n;i++){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(a==b)
					grafo[a][b]=0;
				else
					grafo[a][b]=min(grafo[a][b], grafo[a][i]+grafo[i][b]);
			}
		}
	}

	for(int i=0;i<q;i++){
		int a, b;
		cin>>a>>b;

		cout<<(grafo[a-1][b-1]<1e18?grafo[a-1][b-1]:-1)<<endl;
	}

	return 0;
}
