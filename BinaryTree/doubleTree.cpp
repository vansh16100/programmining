#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
class Node{
    public:
     int data;
     Node* left;
     Node* right;
     Node(int data) {
         this->data = data;
         left=right=NULL;
     }
};
Node* doubleTree(Node* root) {
    if(root==NULL)  return NULL;
    Node* left = doubleTree(root->left);
    Node* right = doubleTree(root->right);
    root->left = new Node(root->data);
    root->left->left = left;
    return root;
}
void inorder(Node* root) {
  if(root==NULL) return ;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void solve() {
  Node* root=new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  inorder(root);
  cout<<endl;
  root = doubleTree(root);
  inorder(root);

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/competitive/input.txt", "r", stdin);
    freopen("E:/competitive/output.txt", "w", stdout);
#endif

solve();

return 0;
 }