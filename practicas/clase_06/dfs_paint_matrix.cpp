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
	/**
	 * Metodo print: Imprime la tabla (-1 es impreso como #)
	 * Atributos:
	 * 	matrix -> vector 2D de los datos
	 */
	int len=matrix.size();
	for(int i=0;i<len;i++){
		for(int u=0;u<len;u++){
			if(matrix[i][u]==-1)
				cout<<"#"<<"\t";
			else
				cout<<matrix[i][u]<<"\t";
		}
		cout<<endl;
	}
}

vector<vector<int>> dfs_matrix_painter(vector<vector<int>> matrix, int fil, int col, int color){
	/**
	 * Metodo dfs_matrix_painter: hace recorrido dfs por el vector 2D (pinta)
	 * Atributos:
	 * 	matrix -> vector 2D de los datos
	 * 	fil    -> coordenada 'y' de la matriz
	 * 	col    -> coordenada 'x' de la matriz
	 * 	color  -> color con el que se pintará la posiciones [fil][col]
	 */
	int len=matrix.size();

	//verificacion de limites, pintado y pared
	if((fil<0||fil>=len||col<0||col>=len) || matrix[fil][col]==-1 || matrix[fil][col]==color)
		return matrix;
	
	matrix[fil][col]=color;//se pinta

	//recorrido de los 4 posibles hijos
	for(int i=0;i<4;i++){
		matrix = dfs_matrix_painter(matrix,fil+son_fil[i],col+son_col[i],color);
	}
	return matrix;
}


int main(){
	/**
	 * Metodo principal con entrada de datos
	 */
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
	x--; y--; //valores de 1-n

	int color;cin>>color;//entrada del color a usar

	cout<<"Before..."<<endl;
	print(matrix);

	//llamado a la funcion
	matrix = dfs_matrix_painter(matrix,x,y,color);


	cout<<"After..."<<endl;
	print(matrix);

	return 0;
}

