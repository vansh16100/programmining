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
    char key;
    vector<Node *> child;
};

// Utility function to create a new tree node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    return temp;
}
int Diameter(Node* root, int &dia) {
    if(root==NULL) return -1;
    int fdch = 0;
    int sdch = 0;
    for(auto it : root->child) {
        int cch = Diameter(it,dia);
        if(cch > fdch) {
          sdch = fdch;
          fdch = cch;
        }else if(cch > sdch) {
            sdch = cch;
        }
    }
    dia = max(dia,fdch + sdch + 1);
    return fdch+1;
}
void solve() {
    cout<<"j";
    Node *root = newNode('A');
    (root->child).push_back(newNode('B'));
    (root->child).push_back(newNode('F'));
    (root->child).push_back(newNode('D'));
    (root->child).push_back(newNode('E'));
    (root->child[0]->child).push_back(newNode('K'));
    (root->child[0]->child).push_back(newNode('J'));
    (root->child[2]->child).push_back(newNode('G'));
    (root->child[3]->child).push_back(newNode('C'));
    (root->child[3]->child).push_back(newNode('H'));
    (root->child[3]->child).push_back(newNode('I'));
    (root->child[0]->child[0]->child).push_back(newNode('N'));
    (root->child[0]->child[0]->child).push_back(newNode('M'));
    (root->child[3]->child[2]->child).push_back(newNode('L'));
    int dia=0;
   
    Diameter(root,dia);
    cout << dia;
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
//  }
return 0;
 }