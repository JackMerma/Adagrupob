#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define li long int
#define endl "\n"
#define PI 3.1415926535897932384626

int main(){
    /*
    Metodo main: principal
    */
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str1,str2;//ambos strings
    vector<int> matchPositions(1000000);//todos los posibles matches

    while(getline(cin,str1), getline(cin, str2)){//siempre que se pueda leer dos lineas
        //la pos indicara desde donde buscar en la palabra
        //el conteo se llevara para alamcenar los matches encontrados
        int pos=0,conteo=0;

        //siempre que haya una coincidencia y 'pos' no sobrepase a str2
        while(str2.find(str1,pos)!=-1 && pos<str2.size()){

            //se almacena la coincidencia
            matchPositions[conteo++]=str2.find(str1,pos);
            
            //se cambia la posicion por la encontrada + 1
            //ahora buscara desde esa posicion + 1 hasta el final  
            pos=matchPositions[conteo-1]+1;
        }

        //se imprimen todas las coincidencias almacenadas
        for(int i=0;i<conteo;i++)
        	cout<<matchPositions[i]<<" ";
        
        cout<<endl;
    }

	return 0;
}