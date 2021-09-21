#include <iostream>
using namespace std;

int main(){
  int n, sum=0;
  cin>>n;

  while(n-->0){
    int num;
    cin>>num;
    sum+=num;
  }
  cout<<sum<<endl;
}
