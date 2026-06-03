#include<iostream>
#include<vector>

using namespace std;

class q{
public:
  vector<int> v;
  
  void push(int val){
   v.push_back(val);
  
  }

  void pop(){
    //erase will resize 
    v.erase(v.begin());
    
  }

  void display() {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}
  
};

int main(){
    q a;
    a.push(8);
    a.push(3);
    a.display();
    a.pop();
    a.display();
    

    return 0;
}