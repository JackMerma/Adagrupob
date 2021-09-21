#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;

  int arr[n];

  //entrada de datos
  for(int i=0;i<n;i++)
    cin>>arr[i];

  //salida en orden inverso
  for(int i=n-1;i>=0;i--)
    cout<<arr[i]<<" ";

  return 0;
}
