#include<iostream>

using namespace std;

int main(){
    int arr[5]={11,12,13};
    for(int val:arr){
      if(val==12){
        val=-1;
      }
      }
       cout<<arr;
    
    return 0;
}