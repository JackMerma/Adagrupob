#include <iostream>
#include <string>
using namespace std;

int main(){

  string str;
  getline(cin,str);

  str = " "+str+" ";

  for(int i=0;i<5;i++){
    if(i==0||i==4){//bordes horizontales
      for(int u=0;u<str.length()+2;u++)
	cout<<"*";
    }else if(i==1||i==3){//bordes verticales
      for(int u=0;u<str.length()+2;u++)
	cout<<((u==0||u+1==str.length()+2)?"*":" ");//si es primero o ultimo dentro de la fila
    }else{//palabra
      cout<<"*"<<str<<"*";
    }
    cout<<endl;
  }

  return 0;
}
