#include <iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int i=0,p=0,imp[n],par[n];//cantidad de impares (i) y pares(p)
  //ambos de capacidad n

  while(i+p<n){
    int num;
    cin>>num;
    
    if(num%2==0){
      par[p]=num;
      p++;
    }else{
      imp[i]=num;
      i++;
    }
  }  

  //mostrando resultados
  cout<<"pares: ";
  for(int j=0;j<p;j++)
    cout<<par[j]<<" ";

  cout<<endl;

  cout<<"impares: ";
  for(int j=0;j<i;j++)
    cout<<imp[j]<<" ";

  return 0;
}
