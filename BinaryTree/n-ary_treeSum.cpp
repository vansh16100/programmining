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
    int key;
    vector<Node*> child;
    Node(int key) {
        this->key = key;
    }
};
void maxSumUtil(Node* root,int &max_sum) {
    if(root==NULL) return;

    int curr = root->key;
    int s = (root->child).size();
   for(Node* it:root->child) {
      curr+=it->key;
      maxSumUtil(it,max_sum);
   }

   max_sum = max(curr , max_sum);

}
Node* newNode(int key) {
    return new Node(key);
}
int maxSum(Node* root) {
    int max_sum = INT_MIN;
    maxSumUtil(root,max_sum);
    return max_sum;
}
void solve() {
    Node *root = newNode(1);
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(3));
    (root->child).push_back(newNode(4));
    (root->child[0]->child).push_back(newNode(5));
    (root->child[0]->child).push_back(newNode(6));
    (root->child[2]->child).push_back(newNode(5));
    (root->child[2]->child).push_back(newNode(6));
    (root->child[2]->child).push_back(newNode(6));

    cout << maxSum(root) << endl;
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
//  }
return 0;
 }