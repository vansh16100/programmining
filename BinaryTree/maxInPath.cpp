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
        left = right = NULL;
    }
};
Node *Insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->data > key)
        root->left = Insert(root->left, key);
    else
        root->right = Insert(root->right, key);
    return root;
}
void LCA(Node* root,int a,int b,Node*& lca) {
    if(root==NULL) return;
    if(root->data==a||root->data==b) {
        lca = root;
        return;
    }
    if ((root->data < a && root->data > b) || ((root->data > a && root->data < b))) {
        lca = root;
        return;
    }
    if(root->data < a) LCA(root->right,a,b,lca);
    else LCA(root->left,a,b,lca);
}
void findMax(Node* root,int d,int &m) {
    if(root==NULL) return;
    m = max(root->data, m);
    if(root->data == d) return;
    if(root->data < d) findMax(root->right,d,m);
    else findMax(root->left,d,m);
}
void solve() {
  Node* root = NULL;
  root = Insert(root,18);
  root = Insert(root, 9);
  root = Insert(root, 36);
  root = Insert(root, 6);
  root = Insert(root, 12);
  root = Insert(root, 1);
  root = Insert(root, 8);
  root = Insert(root, 10);
  Node* lca = NULL;
  LCA(root,1,10,lca);
  cout<<lca->data;
  cout<<"\n";
  int m1,m2;
  m1=m2=INT_MIN;
  findMax(lca,1,m1);
  findMax(lca,10,m2);
  cout<<max(m1,m2)<<"\n";
}
int main() {
#ifndef ONLINE_JUDGE
freopen("e:/competitive/input.txt", "r", stdin);
freopen("e:/competitive/output.txt", "w", stdout);
#endif
// int t;
// cin>>t;
// while(t--){
solve();
//   }
return 0;
 }