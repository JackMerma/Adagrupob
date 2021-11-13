/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 13/11/2021
* @filename    : dfs_paint_matrix
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

void print(vector<vector<int>> tabla){
	int len=tabla.size();
	for(int i=0;i<len;i++){
		for(int u=0;u<len;u++){
			if(tabla[i][u]==-1)
				cout<<"#"<<" ";
			else
				cout<<tabla[i][u]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//entrada de datos
	int n;cin>>n;//longitud de la matriz
	vector<vector<int>> tabla;
	
	//entrada de n*n datos en la matriz
	for(int i=0;i<n;i++)
		for(int u=0;u<n;u++)
			cin>>tabla[i][u];

	int x,y;
	cin>>x>>y;//entrada de puntos a pintar
	x--; y--; //valores de 0-n

	int color;cin>>color;

	cout<<"Before..."<<endl;
	print(tabla);

	//llamado a la funcion
	dfs_matrix_painter(tabla,x,y);


	cout<<"After..."<<endl;
	print(tabla);

	return 0;
}

