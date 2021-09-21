#include <iostream>
using namespace std;

int min(int a, int b){
  //funcion que retorna el menor de dos numeros
  //a y b son los numeros a comparar
  return (a<b)?a:b;
}
    
int main(){

  int a,b,c;
  cin>>a;cin>>b;cin>>c;

  int minNum=min(a,min(b,c));

  if(minNum==a){
    cout<<a<<" ";
    if(min(b,c)==b)
      cout<<b<<" "<<c<<endl;
    else
      cout<<c<<" "<<b<<endl;
  }else if(minNum==b){
    cout<<b<<" ";
    if(min(a,c)==a)
      cout<<a<<" "<<c<<endl;
    else
      cout<<c<<" "<<a<<endl;
  }else{
    cout<<c<<" ";
    if(min(a,b)==a)
      cout<<a<<" "<<b<<endl;
    else
      cout<<b<<" "<<a<<endl;
  }

  return 0;
}
