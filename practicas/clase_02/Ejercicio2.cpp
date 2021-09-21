/*
 * Algoritmo de busqueda lineal usando un metodo
 */
#include <iostream>
using namespace std;

bool search(int arr[],int size,int num){
  for(int i=0;i<size;i++)
    if(arr[i]==num)
      return true;
  return false;
}

int main(){

  int nums[]={1,2,3,4,5,6};

  cout<<((search(nums,sizeof nums/sizeof nums[0],10))?"Encontrado":"No encontrado");
  return 0;
}
