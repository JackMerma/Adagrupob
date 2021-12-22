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
    vector<int> matchPositions(1000000);

    while(getline(cin,str1), getline(cin, str2)){
        int pos=0,conteo=0;

        while(str2.find(str1,conteo)!=-1 && conteo<str2.size()){

            matchPositions[pos++]=str2.find(str1,conteo);
            conteo=matchPositions[pos-1]+1;
        }

        for(int i=0;i<pos;i++)
        	cout<<matchPositions[i]<<" ";
        
        cout<<endl;
    }

	return 0;
}