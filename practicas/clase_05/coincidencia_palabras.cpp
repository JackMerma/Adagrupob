/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 29/10/2021
* @filename    : coincidencia_palabras
* @description : Algoritmo para encontrar la cadena A en la B 
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

/*
 * Complejidad --> O(n*m)
 * --> n : str1.length()
 * --> m : str2.length()
 *
 * Explicacion: En el primer 'while' se recorre a 'm'. Luego, si se encuentra una coincidencia
 *              en la primera letra de str1 y en la posicion i-esima de m, entonces
 *              recorre toda la longitud de str1 en str2.
 *
 *              Explicacion 1:
 *
 *                En otras palabras, en el peor caso str1, seria una cadena de n-1 caracteres iguales
 *                y un caracter final diferente, ejemplo:
 *                -  aaaaax
 *                Por otro lado str2, seria una cadena de m caracteres iguales al primer caracter 
 *                de str1, ejemplo :
 *                - aaaaaaaaaaaaaaaaaaaaaaaa
 * 
 *                Entonces, en general estos casos, darian como resultado n*m comparaciones 
 *                aproximadamente (peor caso).
 * 
 *
 *              Explicacion 2: Usando una matriz de n*m
 *
 *                Si se representara a 0 y 1 con "coincide" y "no coincide" (caracter) respectivamente. 
 *                Entonces: 	 
 *
 *                -> pasada 1: Primer caso
 *
 *                	 1  2  3  4  5  6  7  8  ...  m
 *                1  1
 *                2     1
 *                3        1
 *                4           1
 *               ...
 *                n              0
 *
 *                -> pasada k-esima: Ultimo caso
 *
 *                	 1  2  3  4  5  6  7  8  ...  m
 *                1  1  1  1  1  1  1  1  1  
 *                2     1  1  1  1  1  1  1  
 *                3        1  1  1  1  1  1  
 *                4           1  1  1  1  1     
 *               ...                         
 *                n              0  0  0  0  ...  1
 *
 *                Igual que en el explicacion 1, tendria que comparar en general, n*m posiciones y al 
 *                final encontrar o no encontrar la coincidencia
 *              
 *  
 */
bool find_needle(string needle, string haystack){
	int needle_index=0,haystack_index=0;
	bool found_needle=false;

	while(haystack_index<haystack.length()){
		if(needle[needle_index]==haystack[haystack_index]){
			found_needle=true;
			while(needle_index<needle.length()){
				if(needle[needle_index]!=haystack[haystack_index+needle_index]){
					found_needle=false;
					break;
				}
				needle_index+=1;
			}
			if(found_needle==true)
				return true;
			needle_index=0;
		}
		haystack_index+=1;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//Entrada para dos cadenas
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);

	bool ans=find_needle(str1,str2);
	if(ans)
		cout<<"'"<<str1<<"' in '"<<str2<<"'!"<<endl;
	else
		cout<<"'"<<str1<<"' not in '"<<str2<<"'"<<endl;
	

	return 0;
}
