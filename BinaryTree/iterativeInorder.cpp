#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inOrder(Node* root){
    Node* temp=root;
    if(root==NULL) return;
   stack<Node*> st;
  // st.push(root);
    while(temp!=NULL||!st.empty()) {
         while(temp!=NULL) {
            st.push(temp);
            temp=temp->left;
         }
         temp = st.top();
         st.pop();
         cout<<temp->data<<" ";
         temp = temp->right;
    }
}
void solve() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
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
  //}
return 0;
 }