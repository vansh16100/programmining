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
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
bool bstRange(Node* root,int &count,int min,int max) {
    if(root==NULL) return true;

    bool left = bstRange(root->left,count,min,max);
    bool right = bstRange(root->right,count,min,max);

    if(left&&right&&(root->data <= max&&root->data >= min)) {
        count++;
        return true;
        }
    return false;
}
void solve() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);
    int c=0;
    bstRange(root,c,1,45);
    cout<<c;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/competitive/input.txt", "r", stdin);
    freopen("E:/competitive/output.txt", "w", stdout);
#endif
    solve();

    return 0;
 }