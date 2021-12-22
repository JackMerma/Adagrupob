#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define li long int
#define endl "\n"
#define PI 3.1415926535897932384626

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str1,str2;
    int conteo[100000];

    while(getline(cin,str1), getline(cin, str2)){
        int pos=0,x=0;

        while(str2.find(str1,x)!=-1&&x<str2.size()){

            conteo[pos++]=str2.find(str1,x);
            x=conteo[pos-1]+1;
        }

        for(int i=0;i<pos;i++){
        	cout<<conteo[i];
        	if(i==pos-1){
        		cout<<endl;
        	}else{
        		cout<<" ";
        	}
        }
    }

    for(int i=0;i<str2.length();i++){
    	cout<<conteo[i]<<" ";
    }

	return 0;
}