//O(n)

#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
class node 
{ 
    public:
    int data; 
    node *left, *right; 
}; 
node* newNode(int data) 
{ 
    node* temp = new node();
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void morrisInorder(node* root) {
    node* curr=root;
    while(curr!=NULL) {
        if(curr->left==NULL) {
            cout<<curr->data<<" ";
            curr=curr->right;
        }else {
           node* tmp=curr->left;
           while(tmp->right!=NULL && tmp->right!=curr) {
               tmp=tmp->right;
           }
           if(tmp->right==curr) {
               cout << curr->data << " ";
               curr = curr->right;
               tmp->right = NULL;
              
           }else {
               
               tmp->right=curr;
               curr=curr->left;
           }
        }
    }
}
void morrisPreorder(node* root) {
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            node *tmp = curr->left;
            while (tmp->right != NULL && tmp->right != curr)
            {
                tmp = tmp->right;
            }
            if (tmp->right == curr)
            {
                tmp->right = NULL;
                curr = curr->right;
            }
            else
            {
                cout << curr->data << " ";
                tmp->right = curr;
                curr = curr->left;
            }
        }
    }
}
void solve() {
    node *root = NULL;

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);

    morrisInorder(root);
    cout<<endl;
    morrisPreorder(root);
    cout<<endl;
    diagonal(root);
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
 // }
return 0;
 }