/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 15/11/2021
* @filename    : paren
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

//prototipos
int minimum_parentheses_maker(string);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init_code();

	int caso1=minimum_parentheses_maker("())");
	cout<<"caso 1:"<<caso1<<endl;

	int caso2=minimum_parentheses_maker("(((");
	cout<<"caso 2:"<<caso2<<endl;

	int caso3=minimum_parentheses_maker("(()))(");
	cout<<"caso 3:"<<caso3<<endl;

	int caso4=minimum_parentheses_maker("()))((");
	cout<<"caso 4:"<<caso4<<endl;
	return 0;
}

int minimum_parentheses_maker(string expression){
	stack<char> stack_expression;

	for(int i=0;i<expression.length();i++){
		char actual_character=expression[i];

		if(actual_character=='('){
			stack_expression.push(actual_character);
		}else{
			if(!stack_expression.empty() && stack_expression.top()=='(')
				stack_expression.pop();
			else
				stack_expression.push(')');
		}
	}

	return stack_expression.size();
}
