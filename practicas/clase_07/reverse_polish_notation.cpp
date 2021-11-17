/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 15/11/2021
* @filename    : validate
* @description : _
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626


//prototipos
int operate(string, int, int);
int getResult(string);

void init_code(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init_code();
	
	int result1 = getResult("2 3 +");
	cout << "Resultado 1: " << result1 << endl;

	return 0;
}

int getResult(string expression){
	expression += " ";
	string data;
	int space=expression.find(" ", 0);
	stack<string> stack_expression;

	while(space!=-1){
		string data=expression.substr(0,space); 

		if(data!="+"&&data!="-"&&data!="*"&&data!="/"){
			stack_expression.push(data);
		}else{
			int b,a;
			b=stoi(stack_expression.top());stack_expression.pop();
			a=stoi(stack_expression.top());stack_expression.pop();

			stack_expression.push(to_string(operate(data,a,b)));
		}

		expression=expression.substr(space+1,expression.length()-space-1);
		space=expression.find(" ", 0);
	}

	return stoi(stack_expression.top());
}

int operate(string sig, int a,int b){
	if(sig=="+"){
		return a+b;
	}else if(sig=="-"){
		return a-b;
	}else if(sig=="*"){
		return a*b;
	}else{
		return a/b;
	}
}

