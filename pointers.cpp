#include<iostream>
using namespace std;

class Node{   //size=4+8=12
public:
    int data;
    Node* next;

    Node(int val=0){  //CREATE SPACE!
        data=val;
        next=nullptr;
    }
};


// struct st{   //size=8+8=16 assign higher size to all
//     int data;
//     double val;
// };

// struct st{ 
//     double val;  //size=8+4=12 
//     int data;
// };

void traverse(Node* head){
    if(!head)return;
    while(head){
        std::cout<<head->data<<"-";
        head=head->next;
        
    }
    cout<<"NULL";
}

void addEnd(Node* head,int val){
    if(!head)return; //no head,do nothing
    while(head->next){//n4
        head=head->next;//n4
    }
Node* newNode=new Node(val);
head->next=newNode;
}

void addBegin(Node* head,int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;  
}

void addatmid(Node* &head,int val,int pos){
if(!head)addBegin(head,val);
pos-=2;int cnt=0;
while(head&&cnt<pos){
    head=head->next;
    cnt++;
}
Node* newnode = new Node(val);
newnode->next =head->next;
head->next=newnode;
}

int main(){
    Node* head;
    Node* n1=new Node(5);
    head=n1;
    Node* n2=new Node(15);
    n1->next=n2;
    Node* n3=new Node(25);
    n2->next=n3;
    Node* n4=new Node(35);
    n3->next=n4;
    traverse(head);
    addEnd(head,25);
    traverse(head);
    

}