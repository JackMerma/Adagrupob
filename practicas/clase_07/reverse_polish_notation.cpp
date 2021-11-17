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

int main(){
	/**
	 * Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//casos

	int result1 = getResult("2 1 + 3 *");
	cout<<"Resultado 1:"<<result1<<endl;

	int result2 = getResult("4 13 5 / +");
	cout<<"Resultado 2:"<<result2<<endl;

	int result3 = getResult("10 6 9 3 + -11 * / * 17 + 5 +");
	cout<<"Resultado 3:"<<result3<<endl;


	return 0;
}

int getResult(string expression){
	/**
	 * Metodo getResult: procesa la expresion (cadena)
	 * Atributos:
	 * 	expression -> cadena a procesar
	 */
	expression += " "; //para no obtener errores

	string data;//numero o operacion
	stack<string> stack_expression;//stack principal

	int space=expression.find(" ", 0);//coincidencia con el primer espacio

	while(space!=-1){//siempre que haya algo mas que agregar

		string data=expression.substr(0,space);//se obtiene la data

		if(data!="+"&&data!="-"&&data!="*"&&data!="/"){//si es numero, solo se agrega
			stack_expression.push(data);
		}else{//si es operador, se opera con los dos ultimos numeros del stack
			int b,a;
			b=stoi(stack_expression.top());stack_expression.pop();
			a=stoi(stack_expression.top());stack_expression.pop();

			stack_expression.push(to_string(operate(data,a,b)));//se coloca el resultado en el stack
		}

		expression=expression.substr(space+1,expression.length()-space-1);//eliminacion de la primera subcadena
		space=expression.find(" ", 0);//se vuelve a buscar un espacio
	}

	return stoi(stack_expression.top());//el resultado sera el unico dato en el stack
}

int operate(string sig, int a,int b){
	/**
	 *	Metodo operate: opera dos numeros, respecto al operador enviado
	 *	Atributos:
	 *		sig -> el operador enviado
	 *		a   -> primero numero
	 *		b   -> segundo numero
	 */
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
