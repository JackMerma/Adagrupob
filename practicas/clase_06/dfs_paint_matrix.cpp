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

	vector<vector<int>> m1=
	{	{-1, -1, 0, 0, -1},
		{0, 0, 0, 0, 0},
		{-1, -1, -1, -1, -1},
		{-1, -1, 0, -1, 0},
		{-1, 0, 0, -1, 0},
	};

	vector<vector<int>> m2=
	{	{-1, -1, 0, 0, -1, 0, 0, 0, 0, 0},
		{-1, -1, -1, -1, -1, -1, -1, 0, -1, 0},
		{-1, 0, 0, -1, 0, 0, -1, 0, 0, -1},
		{-1, 0, -1, 0, -1, 0, -1, -1, -1, 0},
		{-1, -1, 0, -1, -1, 0, -1, -1, -1, 0},
		{-1, 0, 0, -1, -1, -1, -1, -1, -1, 0},
		{0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, -1, 0, -1, 0, 0, 0, -1, -1, 0},
		{-1, -1, 0, 0, 0, 0, 0, 0, -1, 0},
		{0, -1, 0, -1, -1, 0, 0, 0, -1, -1},
	};
	vector<vector<int>> m3=
	{	{-1, -1, 0, 0},
		{-1, 0, 0, 0},
		{0, 0, -1, -1},
		{-1, -1, -1, -1},
	};

	//caso 1
	cout<<"Matriz 1:"<<endl;
	print(m1);
	m1=dfs_matrix_painter(m1,1,0,3);
	cout<<"luego ..."<<endl;
	print(m1);

	//caso2
	cout<<"Matriz 2:"<<endl;
	print(m2);
	m2=dfs_matrix_painter(m2,6,2,7);
	cout<<"luego ..."<<endl;
	print(m2);

	//caso 3
	cout<<"Matriz 3:"<<endl;
	print(m3);
	m3=dfs_matrix_painter(m3,0,3,9);
	cout<<"luego ..."<<endl;
	print(m3);

	return 0;
}

