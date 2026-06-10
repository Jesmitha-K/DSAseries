#include<iostream>
#include<queue>
using namespace std;

class treeNode{
public:
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
    };

     void preorder(treeNode* root) {
    if(root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

    void inorder(treeNode* root) {
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

  void postorder(treeNode* root) {
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    
}

void bfs(treeNode* root){
    if(root == nullptr) 
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty){
        treeNode* currNode=q.front();
        q.pop();
        cout<<currNode->data<<endl;
        if(currNode->left!=nullptr)
          q.push(currNode->left);
        if(currNode->right!=nullptr)
          q.push(currNode->right);

    }
}



int main(){
treeNode* root=new treeNode(1);
root->left=new treeNode(2);
root->right=new treeNode(3);
root->left->left=new treeNode(4);
root->left->right=new treeNode(5);
root->right->right=new treeNode(6);
root->right->left=new treeNode(7);
preorder(root);
postorder(root);
inorder(root);
return 0;
}