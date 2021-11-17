/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 16/11/2021
* @filename    : caps_lock
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

void init_code(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}


queue<char> change(queue<char> q){
	queue<char> new_queue;
	while(!q.empty()){
		char dato=q.front();

		if((int)dato<97)//era mayuscula
			dato=tolower(dato);
		else
			dato=toupper(dato);

		new_queue.push(dato);
		q.pop();
	}
	return new_queue;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init_code();
	
	string str;cin>>str;

	queue<char> que;
	string result="";
	bool arroba=false;

	for(int i=0;i<str.length();i++){
		if(str[i]!='$'&&str[i]!='@'){
			que.push(str[i]);
		}else{
			if(str[i]=='@'){
				arroba=!arroba;
			}else{//$ suelta el buffer
				if(arroba)
					que=change(que);
				while(!que.empty()){
					result.append(1,que.front());
					que.pop();
				}
			}
		}
	}
	cout<<"cadena final:"<<result<<endl;

	return 0;
}

