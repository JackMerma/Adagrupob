/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 16/11/2021
* @filename    : caps_lock
* @description : Problema Caps Lock, donde se transforma una expresion en cadena convirtiendola en ciertos casos subcadenas en mayusculas
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

//prototipos
queue<char> change(queue<char>);
void make_caps_lock(string);

int main(){
	/**
	 *  Metodo principal
	 */
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//Se asegura que la entrada sea de letras minusculas
	make_caps_lock("abc$d@ef$@g$");//caso 1
	make_caps_lock("abc@def$@h$o@$l@$a@$");//caso 2
	make_caps_lock("xyz@$xyz@$");//caso 3

	return 0;
}

void make_caps_lock(string expression){
	/**
	 *  Metodo make_caps_lock: recibe la cadena a transformar e imprime el resultado segun el problema de caps lock
	 *  Atributos:
	 *  	expression -> cadena que será convertida al producto final
	 */
	queue<char> principal_queue;//queue que actuará como buffer
	string result="";//se almacena el resultado
	bool arroba=false;//condicion que ayudara a determinar el estado del arroba 

	//algoritmo
	for(int i=0;i<expression.length();i++){//recorre toda la cadena
		if(expression[i]!='$'&&expression[i]!='@'){//si es una letra, se agregar al buffer
			principal_queue.push(expression[i]);
		}else{//de lo contrario
			if(expression[i]=='@'){//si es el arroba, se niega este -> positivo a negativo y negativo a positivo
				arroba=!arroba;
			}else{//$ suelta el buffer
				if(arroba)//antes de soltar el buffer, cambia las letras a mayusculas
					principal_queue=change(principal_queue);
				while(!principal_queue.empty()){//suelta el buffer
					result.append(1,principal_queue.front());
					principal_queue.pop();
				}
			}
		}
	}
	//impresion del resultado
	cout<<"Cadena final:"<<result<<endl;
}

queue<char> change(queue<char> queue_to_change){
	/**
	 *  Metodo change: cambia al sentido contrario el estado del caracter
	 *  Atributos:
	 *  	queue_to_change -> Queue a cambiar los datos
	 */
	queue<char> new_queue;//queue a devolver

	//algoritmo
	while(!queue_to_change.empty()){
		char dato=queue_to_change.front();

		if((int)dato<97)//Si era mayuscula
			dato=tolower(dato);
		else//si era minuscula
			dato=toupper(dato);

		new_queue.push(dato);//almacena resultado
		queue_to_change.pop();
	}
	return new_queue;//devuelve resultado
}
