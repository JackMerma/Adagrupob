/**
 * Programa: Busqueda Binaria usando un arreglo estandar
 * @author Jackson Fernando Merma Portocarrero
 */
#include <iostream>
using namespace std;

int main(){

	int arr[]={1,3,4,6,15,17,19,30};
	int len=sizeof arr/sizeof arr[0];
	int min=0,max=len-1,pos;

	int num;
	cin>>num;

	while(min<=max){
		pos=min+(max-min)/2;
		if(arr[pos]==num){
			cout<<"Encontrado"<<endl;
			break;
		}
		if(arr[pos]>num){
			max=pos-1;
		}else{
			min=pos+1;
		}
	}
	cout<<"terminado";
	return 0;
}
