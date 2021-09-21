#include <iostream>
using namespace std;

int main() {

  int nums[]={12,1,6,7,4,11,0,5};

  int len=sizeof nums/sizeof nums[0];

  for(int i=1;i<len;i++){
    int key=nums[i];

    int j=i-1;
    while(j>=0&&nums[j]>key){
      nums[j+1]=nums[j];
      j-=1;
    }
    nums[j+1]=key;
  }

  for(int i=0;i<len;i++){
    cout<<nums[i]<<" ";
  }

  return 0;
}
