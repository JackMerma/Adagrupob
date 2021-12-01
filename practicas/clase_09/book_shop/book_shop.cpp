/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : book_shop
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//entrada de n y maxima cantidad
	int n,CANT;
	cin>>n>>CANT;
	
	//datos
	int price[n]={0};
	int pages[n]={0};

	//entrada de precios y paginas
	for(int i=0;i<n;i++)
		cin>>price[i];
	for(int i=0;i<n;i++)
		cin>>pages[i];

	//matriz principal
	int data[n+1][CANT+1];

	//recorrido dinamico
	for(int i=0;i<=n;i++){
		for(int u=0;u<=CANT;u++){
			if(i==0||u==0) //primera fila y columna
				data[i][u]=0;
			else if(price[i-1] <= u)//si hay capacidad
				//se maximiza entre el actual y la resta en la fila anterior ya maximizada
				data[i][u]=max(pages[i-1]+data[i-1][u-price[i-1]], data[i-1][u]);
			else//si no se maximiza, sera el anterior(ya maximizado)
				data[i][u]=data[i-1][u];
		}
	}
	
	cout<<data[n][CANT]<<endl;//el ultimo dato sera el maximizado

	return 0;
}

