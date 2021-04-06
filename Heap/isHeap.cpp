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
        left=NULL;
        right=NULL;
    }
};
 bool isHeap(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    if (root->data < root->left->data)
        return false;

    if (root->data < root->right->data)
        return false;

    return isHeap(root->left) && isHeap(root->right);
}
void solve() {
  Node *root = new Node(2);
  root->left = new Node(3);
  root->right = new Node(4);
  root->left->left = new Node(1);
  root->left->right = new Node(2);
  cout<<isHeap(root);

}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
// int t;
// cin>>t;
// while(t--){
solve();
//   }
return 0;
 }