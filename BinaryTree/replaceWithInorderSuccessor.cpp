#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
class Node {
    public:
     int data;
     Node* left;
     Node* right;
     Node(int data) {
         this->data = data;
         left=right=NULL;
     }
};
Node* Insert(Node* root,int key) {
    if(root==NULL) return new Node(key);
    if(root->data > key) root->left = Insert(root->left,key);
    else root->right = Insert(root->right,key);
    return root;
}
Node* findSucc(Node* root) {
    Node* temp = root;
    while(temp->left!=NULL) {
        temp=temp->left;
    }
    return temp;
}
Node* Delete(Node* root,int key) {
    if(root==NULL) return NULL;

    if(root->data > key) {
      root->left = Delete(root->left,key);
    }else if(root->data < key) {
      root->right = Delete(root->right,key);
    }else {
      if(root->right&&root->left){
           Node* temp = findSucc(root->right);
           swap(temp->data,root->data);
           root->right = Delete(root->right,key);
      }else if(root->right) {
         Node* temp =root;
         delete temp;
         root = root->right;
      }else if(root->left){
         Node* temp = root;
         delete temp;
         root=root->left;
      }else {
          delete root;
          root=NULL;
      }
    }
    return root;
}
void inorder(Node* root) {
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void findSuccessor(Node *root, int key, Node *&suc)
{
    Node *temp = root;
    while (temp != NULL){
        if (temp->data == key) break;
        if (temp->data < key) {
            temp = temp->right;
        }
        else  {
            suc = temp;
            temp = temp->left;
        }
    }
}
void find(Node *root, Node *key,Node *&suc)
{
    if (key->right) {
        suc = key->right;
        while (suc->left != NULL) {
            suc = suc->left;
        }
    }
    else
        findSuccessor(root, key->data, suc);
}
Node* findInorderSuccessor(Node* root,int key) {
    Node* succ = NULL;
    Node *temp = root;
    while (temp != NULL){
        if (temp->data < key){
            temp = temp->right;
        }
        else if (temp->data > key){
            temp = temp->left;
        }
        else{
            break;
        }
    }
    find(root,temp,succ);
    return succ;
}
void solve() {
    vector<int> v = {8, 58, 71, 18, 31, 32, 63, 92,
                     43, 3, 91, 93, 25, 80, 28};
     Node *root = NULL;
     int n = v.size();
     for(int i=0;i<n;i++) {
         root = Insert(root,v[i]);
     }
        Node* succ;
      for(int i=0;i<n;i++) {
        succ = findInorderSuccessor(root,v[i]);
        int tmp = v[i];
        if(succ==NULL) v[i] = -1;
        else v[i] = succ->data;
        Node *temp = Delete(root, tmp);
        root=temp;
       }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
   }
}
int main() {
#ifndef ONLINE_JUDGE
freopen("e:/competitive/input.txt", "r", stdin);
freopen("e:/competitive/output.txt", "w", stdout);
#endif
solve();
  
return 0;
 }