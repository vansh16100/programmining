#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#define ll long long int
#define pii pair<int, int>
#define pic pair<int, char>
using namespace std;
using v_i = vector<int>;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node* modify(Node* root,int min,int max) {
    if(root==NULL) return NULL;
    root->left = modify(root->left,min,max);
    root->right = modify(root->right,min,max);

    if(root->data < min) {
        Node* child = root->right;
        delete root;
        return child;
    }
    if(root->data > max) {
        Node* child = root->left;
        delete root;
        return child;
    }

    return root;
}
void inorder(Node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void solve()
{
    Node *root = new Node(6);
    root->left = new Node(-13);
    root->right = new Node(14);
    root->left->right = new Node(-8);
    root->right->right = new Node(15);
    root->right->left = new Node(13);
    root->right->left->left = new Node(7);
    inorder(root);
    cout<<endl;
    root = modify(root,-10,13);
    inorder(root);
}
int main()
{
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