/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 11/11/2021
* @filename    : sqrt_binary_function
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626


int search_root(int number){
	/**
	 * Documentacion......
	 */
	float ans;
	int a=0,b=number;

	while(a<b-1){
		cout<<a<<" "<<b<<endl;
		ans=(a+b)/2;
		if(ans*ans==number) return (int)ans;
		if(ans*ans>number){
			b=ans;
		}else{
			a=ans;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int number; cin>>number;

	int root=search_root(number);
	if(root==-1){
		cout<<"No tiene raiz exacta"<<endl;
	}else{
		cout<<"Raiz de "<<number<<": "<<root<<endl;
	}

	return 0;
}

