/** 
* @author      : Jackson Fernando Merma Portocmatrixero (jmermap@unsa.edu.pe)
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

//recorrido -> arriba, abajo, izquierda, derecha
int son_fil[4]={-1,1,0,0};
int son_col[4]={0,0,-1,1};

void print(vector<vector<int>> matrix){
	int len=matrix.size();
	for(int i=0;i<len;i++){
		for(int u=0;u<len;u++){
			if(matrix[i][u]==-1)
				cout<<"#"<<" ";
			else
				cout<<matrix[i][u]<<" ";
		}
		cout<<endl;
	}
}

vector<vector<int>> dfs_matrix_painter(vector<vector<int>> matrix, int fil, int col, int color){
	int len=matrix.size();
	if((fil<0||fil>=len||col<0||col>=len) || matrix[fil][col]==-1 || matrix[fil][col]==color) //se verifica en un inicio
		return matrix;
	matrix[fil][col]=color;
	print(matrix);
	cout<<endl;
	//recorrido de los hijos -> son[fil][col]
	for(int i=0;i<4;i++){
		matrix = dfs_matrix_painter(matrix,fil+son_fil[i],col+son_col[i],color);
	}
	return matrix;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//entrada de datos
	int n;cin>>n;//longitud de la matriz
	vector<vector<int>> matrix;
	
	//entrada de n*n datos en la matriz
	for(int i=0;i<n;i++){
		vector<int> aux;
		for(int u=0;u<n;u++){
			int num;cin>>num;
			aux.push_back(num);
		}
		matrix.push_back(aux);
	}

	int x,y;
	cin>>x>>y;//entrada de puntos a iniciar
	x--; y--; //valores de 0-n

	int color;cin>>color;

	cout<<"Before..."<<endl;
	print(matrix);

	//llamado a la funcion
	matrix = dfs_matrix_painter(matrix,x,y,color);


	cout<<"After..."<<endl;
	print(matrix);

	return 0;
}

