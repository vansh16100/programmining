//vertex cover problem
// it is dynamic programming problem
// this algorithm takes the example you can create the tree on your own

#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
//#include INF INT_MAX
class node{
public:
  int data;
  node* left;
  node* right;
  node(int data) {
    this->data = data;
    left=NULL;
    right=NULL;
  }
};
class binaryTree{
public:
   node* root;
   binaryTree() {
      root=NULL;
   }
   void addNode(int data) {
      if(root==NULL) {
        root=new node(data);
        return;
      }
      queue<node*> q;
      q.push(root);
      while(!q.empty()) {
        node* curr = q.front();
        q.pop();
        if(curr->left) q.push(curr->left);
        else {curr->left = new node(data);break;}
        if(curr->right) q.push(curr->right);
        else {curr->right = new node(data);break;}
      }
   }
};
void inorder1(node* root,map<node*,int> &dp) {
  if(root==NULL) return;
  inorder1(root->left,dp);
   dp[root] = -1;
  inorder1(root->right,dp);
}
int vertexCover(node* root,map<node*,int> &dp) {
  if(root==NULL) return 0;
  if(root->left==NULL&&root->right==NULL) return 0;

  if(dp[root]!=-1) return dp[root];

  int inclusive = 0;
  inclusive = 1+vertexCover(root->left,dp)+vertexCover(root->right,dp);  //take root as the element present in vertex cover
  int exclusive=0;
  if(root->left)
    exclusive+=1+vertexCover(root->left->left,dp)+vertexCover(root->left->right,dp);

  if(root->right)
    exclusive+=1+vertexCover(root->right->left,dp)+vertexCover(root->right->right,dp);
  
  dp[root] = min(inclusive,exclusive);
  return dp[root];
}
void solve() {
   node* root = new node(10);
   root->left = new node(20);
   root->right = new node(30);
   root->left->left = new node(40);
   root->left->right = new node(50);
   root->right->right= new node(60);
   root->left->right->left = new node(70);
   root->left->right->right = new node(80);
   map<node*,int> dp;
   inorder1(root,dp);
   cout<<vertexCover(root,dp);
}
int main() {
    // int t;
    // cin>>t;
    // while(t--){
        solve();
//    }
    return 0;
}
