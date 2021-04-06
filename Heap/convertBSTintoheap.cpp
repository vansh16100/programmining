#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void Inorder(Node* root ,vector<int> &inorder){
    if(root==NULL) return;
    Inorder(root->left,inorder);
    inorder.push_back(root->data);
    Inorder(root->right,inorder);
}
void bstToHeap(Node* root,vector<int> in,int &i) {
    if(root==NULL) return;
    root->data = in[i];
    i++;
    bstToHeap(root->left,in,i);
    bstToHeap(root->right,in,i);
}
void preorder(Node* root) {
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void  BSTtoMinHeap(Node* root) {
    if(root==NULL) return;

    vector<int> inorder;
    int i=0;
    Inorder(root,inorder);
    bstToHeap(root,inorder,i);
    preorder(root);
}
void solve() {
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(7);

   BSTtoMinHeap(root);
}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
// int t;
// cin>>t;
//while(t--){
solve();
 // }
return 0;
 }