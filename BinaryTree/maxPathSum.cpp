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
     Node* left,*right;
     Node(int data) {
         this->data = data;
         left=right = NULL;
     }
};
int maxPathSum(Node* root,int &res) {
    if(root==NULL) return 0;
    int l = maxPathSum(root->left,(res));
    int r = maxPathSum(root->right,(res));
    
    int max1 = max(max(l+root->data,r+root->data),root->data);
    res = max(max(res,max1),l+r+root->data);
    return max1; 
}
void solve() {
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    int res = INT_MIN; 
       cout<<maxPathSum(root,res)<<"\n";
       cout<<res<<" ";
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/competitive/input.txt", "r", stdin);
    freopen("E:/competitive/output.txt", "w", stdout);
#endif
// int t;
// cin>>t;
// while(t--){
solve();
 // }
return 0;
 }