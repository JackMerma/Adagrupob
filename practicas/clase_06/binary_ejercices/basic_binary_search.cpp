/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : basic_binary_search
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

int search(int *arr,int len,int num){
	int a=0,b=len-1;

	//buscando
	while(a<=b){
		int middle=(a+b)/2;

		if(arr[middle]==num) return middle;

		if(arr[middle]>num){
			b=middle-1;
		}else{
			a=middle+1;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int cant;cin>>cant;
	int arr[cant];

	for(int i=0;i<cant;i++) cin>>arr[i];

	int num;cin>>num;

	
	int pos=search(arr,cant,num);
	if(pos==-1) cout<<"No encontrado"<<endl;
	else cout<<"Encontrado en la posicion: "<<pos+1<<endl;

	return 0;
}

