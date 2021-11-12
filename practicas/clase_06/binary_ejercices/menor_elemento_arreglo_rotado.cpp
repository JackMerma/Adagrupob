/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : menor_elemento_arreglo_rotado
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

int searchRotatedArr(int *arr, int len){
	int a=0,b=len-1,m=(a+b)/2;

	while(a<b){
		//cout<<a<<"<"<<m<<">"<<b<<": "<<arr[m]<<endl;
		if(arr[m]<arr[0]){
			b=m;
		}else{
			a=m+1;
		}
		m=(a+b)/2;
	}
	return min(arr[m],arr[0]);//si esta ordenado
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int cant;cin>>cant;
	int arr[cant];

	for(int i=0;i<cant;i++) cin>>arr[i];

	int minElemento=searchRotatedArr(arr,cant);
	cout<<"Minimo encontrado:"<<minElemento<<endl;


	return 0;
}

