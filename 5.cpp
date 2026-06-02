#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v={1,2,3,5,7,9};
    int k;
    cin>>k;
    k=k%v.size();

    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    for(int i:v)
    cout<<" ";

return 0;

}