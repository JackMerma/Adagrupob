/*
 * Entrada de n numeros y conteo de cuantos de estos son multiplos de k
 */
#include <iostream>
using namespace std;

int main(){

  int n,k,count=0;

  cin>>n;cin>>k;

  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    count+=(num!=0&&num%k==0)?1:0;
  }
  cout<<count;

  return 0;
}
