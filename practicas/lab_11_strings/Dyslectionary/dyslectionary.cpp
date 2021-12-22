/**

Author: Jackson Fernando Merma Portocarrero
Problema: Dyslectionary
 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626


string str;

void process(vector<string> palabras){
	int len=palabras[0].length;
	for(int i=1;i<palabras.size();i++){
		len=max(len, palabras[i].length);
		//if(palabras[i].length()>len)
		//	len=palabras[i].length();
	}

	for(int i=0;i<palabras.size();i++)
		reverse(palabras[i].begin(), palabras[i].end());

	sort(palabras.begin(), palabras.end());

	for(int i=0;i<palabras.size();i++)
		reverse(palabras[i].begin(), palabras[i].end());

	for(int i=0;i<palabras.size();i++){
		string gg;
		gg.resize(len - palabras[i].length(), ' ');
		gg+=palabras[i];
		swap(palabras[i], gg);
	}

	for(int i=0;i<palabras.size();i++)
		cpalabras<<palabras[i]<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> palabras;

	while(getline(cin, str)){
		if(str.empty()){
			process(palabras);
			palabras.clear();
			cpalabras<<endl;
		}else{
			palabras.push_back(str);
		}
	}
	process(palabras);
	return 0;
}
