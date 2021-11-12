/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : mayor_o_igual
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626


int search_equal_or_next(int *arr,int len,int found){
	int a=0,b=len-1;
	int middle;

	while(a<=  b){
		middle=(a+b)/2;
		if(arr[middle]==found) return arr[middle];
		
		if(arr[middle]>found){
			b=middle-1;
		}else{
			a=middle+1;
		}
	}

	//la posicion acta
	if(found>arr[len-1]) return -1;//no existe
	return arr[middle];//posicion actual
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int cant;cin>>cant;
	int numbers[cant];

	for(int i=0;i<cant;i++) cin>>numbers[i];

	//numero a encontrar o mayor a este
	int found;cin>>found;




	int number_searching=search_equal_or_next(numbers,cant,found);

	if(number_searching==-1)
		cout<<"No hay mayor o igual que "<<found<<endl;
	else
		cout<<"Mayor o igual que "<<found<<": "<<number_searching<<endl;



	return 0;
}

