#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int data){
        val=data;
        left=right=NULL;
    }

};

int countnode(node* root){

    if(root==NULL)
       return 0;
    else
       if(root->left!=NULL&&root->right!=NULL)
            return 1+countnode(root->left)+countnode(root->right);
        else 
          return countnode(root->left)+countnode(root->right);
}
int main(){
    node*root=new node('A');
    root->left=new node('B');
    root->right=new node('C');
    root->left->left=new node('D');
    root->left->right=new node('E');
    root->right->right= new node('F');
    
    cout<<"count of nodes: "<<countnode(root);

}



