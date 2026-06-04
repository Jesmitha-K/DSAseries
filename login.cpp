#include<iostream>
#include<unordered_map>
using namespace std;

auto untie_cin=cin.tie(0);
auto untie_cout=cout.tie(0);

class person{
protected:
    string name;
    string age;
    long long phno;
    string status;
};

class admin:public person{   
    public:
    int n; 
};

class admin2:public admin{  
};


int main(){
    admin2 a;
    a.n=2.5;
    cout<<a.n;

}
