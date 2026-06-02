#include<iostream>
#include<cstring>

using namespace std;

// string substr(int st,int end,string original){
//     string result;
//     for(int i=st;i<end;i++){
//         result=result+original[i];
//     }
//     return result;
// }

bool empty(string str) {
    bool flag = false;
    int count = 0;

    for(char c : str) {
        count++;
    }

    if(count != 0) {
        flag = true;
    }

    return flag;
}

// int find(string original,string target){
//   for(int i=0;i<original.size();i++){
//     if(original[i]==target[0]){
//      return i;
//   }
// }
// }

//string append(string str1,string str2){
//  str1=str1+str2;
//  return str1;

// }



int main(){
   // string name;
   // string dept;
    //string classno;
    //getline(cin,name);
    //getline(cin,dept);
    //getline(cin,classno);
    //cout<<name<<dept<<classno;
    //string result=substr(1,4,"hello");
    //cout<<result;
    //cout<<"length"<<result.length();
    //cout<<"size"<<result.size();
    cout<<empty("helloo");
    //cout<<append("hai","hello");
    //cout<<find("happy","p");
    return 0;
}