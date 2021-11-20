/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 17/11/2021
* @filename    : backspace
* @description : Dada una cadena, elimina el ultimo caracter de haber un #
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

//prototipo
void back_space(string);

int main(){
	/**
	 *  Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//llamado a la funcion back_space
	back_space("abc#de##f#ghi#jklmn#op#");
	back_space("abcd###");
	back_space("abcd#e#f#g#");

	return 0;
}

void back_space(string expression){
	/**
	 *  Metodo back_space: realiza el proceso back_space con la expresion enviada
	 *  Atributos:
	 *  	expression -> cadena a realizar el back_space 
	 */
	deque<char> deque_letters;//deque principal

	for(int i=0;i<expression.length();i++){//se recorre toda la cadena
		if(expression[i]!='#'){//si NO #, se agrega al final
			deque_letters.push_back(expression[i]);
		}else{//si es #, se elimina siempre que haya algun dato en el deque
			if(!deque_letters.empty()){
				deque_letters.pop_back();
			}
		}
	}

	while(!deque_letters.empty()){//se recorre el resultado del deque
		cout<<deque_letters.front();
		deque_letters.pop_front();
	}
	cout<<endl;
}
