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


/*
Explicacion:

Para su solucion, solamente se usara un sort que pueda ordenar las palabras
en el orden deseado.

1. Primero se encuentra la logitud de la palabra mas larga de un subgrupo
2. Segundo, se hace un reverse a todas las palabras del subgrupo
3. Se hace el sort (ordenara alfabeticamente)
4. Se hace un reverse de nuevo, para que las palabras vuelvan a su 
   estado normal.
5. Se rellenan las palabras al inicio con espacios vacios, para ellos
   se usa la funcion str.resize(), donde se especificara la cantidad de 
   espacios vacios en cada palabra, este numero sera la longitud maxima
   hallada en el paso 1 menos la longitud de la palabra actual.
6. Finalmente se imprime el subgrupo

*/

string str;

void process(vector<string> palabras){
	/*
	Metodo process: procesa cada grupo con los requerimientos
			que son, el de ordenar al grupo por la ultima letra de la palabra

	Atributos:
		palabras -> vector principal de palabras
	*/

	//buscando la maxima longitud de una palabra en el subgrupo 
	int len=palabras[0].length();
	for(int i=1;i<palabras.size();i++){
		if(palabras[i].length()>len)
			len=palabras[i].length();
	}

	//Se invierte cada palabra para hacer un sort simple
	for(int i=0;i<palabras.size();i++)
		reverse(palabras[i].begin(), palabras[i].end());

	//se ordenan las palabras
	sort(palabras.begin(), palabras.end());

	//se vuelve a hacer un reverse, para que queden como inicialmente estaban
	for(int i=0;i<palabras.size();i++)
		reverse(palabras[i].begin(), palabras[i].end());

	//Coloca espacios vacios en cada palabra
	for(int i=0;i<palabras.size();i++){
		string newStr;
		newStr.resize(len - palabras[i].length(), ' ');//los espacios que faltan se agregan
		newStr+=palabras[i];//al final se agrega la palabra normal
		swap(palabras[i], newStr);//se cambia por el resultado final
	}

	//imprimiendo las palabras en el orden dado
	for(int i=0;i<palabras.size();i++)
		cout<<palabras[i]<<endl;
}

int main(){
	/*
	Metodo main: principal
	*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> palabras;//vector para la salida de palabras

	while(getline(cin, str)){//siempre que haya entrada para una palabra
		if(str.empty()){//si es salto de linea, entonces se procesa al grupo
			process(palabras);//procesa las palabras en el vector 'palabras'
			palabras.clear();//limpia el vector
			cout<<endl;//salto de linea
		}else{
			palabras.push_back(str);//agrega una palabra al vector 'palabras'
		}
	}
	process(palabras);//el grupo final se procesa

	
	return 0;
}
