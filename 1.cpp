#include<iostream>
#include<vector>

using namespace std;

class animal{
    public:
    void sound(){
        cout<<"general"<<endl;
    }
};

class dog:public animal{
    public:
    void sound(){
        cout<<"bow"<<endl;
    }
};

int main(){
    animal* a=new dog;
    a->sound();
}