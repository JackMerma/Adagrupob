#include <iostream>
#include <string>
using namespace std;

int main(){

  int esp;
  string str;

  getline(cin,str);
  cin>>esp;

  for(int i=0;i<esp*2+3;i++){
    if(i==0||i+1==esp*2+3){//bordes horizontales
      for(int u=0;u<str.length()+2+esp*2;u++)
	cout<<"*";
    }else if(i==(esp*2+3)/2){//mitad
      cout<<"*";
      for(int u=0;u<esp;u++)
	cout<<" ";
      cout<<str;//medio
      for(int u=0;u<esp;u++)
	cout<<" ";
      cout<<"*";
    }else{//vacios
      for(int u=0;u<str.length()+2+esp*2;u++)
	cout<<((u==0||u+1==str.length()+2+esp*2)?"*":" ");
    }
    cout<<endl;
  }

  return 0;
}

