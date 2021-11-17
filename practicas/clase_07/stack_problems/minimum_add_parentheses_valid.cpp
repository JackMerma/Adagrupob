/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 15/11/2021
* @filename    : paren
* @description : Encuentra el minimo de parentesis para que una expression sea aceptada
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

//prototipos
int minimum_parentheses_maker(string);

int main(){
	/**
	 * Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);

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
	/**
	 * Metodo minimum_parentheses_maker: encuentra el minimo de parentesis en error
	 * Atributos:
	 * 	expression -> expresion principal
	 */
	stack<char> stack_expression;//stack principal

	for(int i=0;i<expression.length();i++){//se recorre toda la expresion
		char actual_character=expression[i];

		if(actual_character=='('){//si es de apertura se agrega
			stack_expression.push(actual_character);
		}else{//si es de cierre, se puede cerrar un grupo
			if(!stack_expression.empty() && stack_expression.top()=='(')//si el stack no esta vacio y se puede formar grupo con el ultimo
				stack_expression.pop();//se elimina al ultimo
			else
				stack_expression.push(')');//se coloca como incorrecto
		}
	}

	return stack_expression.size();//el estack almacenara a los incorrectos -> longitud es la respuesta
}
