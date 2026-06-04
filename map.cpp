#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,string> unordered;
    unordered.insert({0,"zero"});
    unordered[1]="one";
    unordered[2]="two";
    for(auto m:unordered){
        cout<<m.first<<m.second<<endl;
    }
    unordered.erase(0);
    cout<<"erased"<<endl;
    for(auto m:unordered){
        cout<<m.first<<m.second<<endl;
    }


    
return 0;
}