#include<iostream>
#include<vector>

using namespace std;

class st{
public:
  vector<int> v;
  
  void push(int val){
   v.push_back(val);
  
  }

  void pop(){
    v.pop_back();
    
  }

  void display() {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}
  
};

int main(){
    st a;
    a.push(8);
    a.push(3);
    a.display();
    a.pop();
    a.display();
    

    return 0;
}