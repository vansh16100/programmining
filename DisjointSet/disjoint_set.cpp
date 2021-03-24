#include<bits/stdc++.h>
using namespace std;
template<typename T>
class DisjointSet {
   class Node {
    public:
       T data;
       int rank;
       Node* parent;
       Node(T data) {
          this->data=data;
          rank=0;
          parent=this;
       }
   };
       unordered_map<T,Node*> mp;

    public:
       DisjointSet(vector<int> x) {
          for(int i=0;i<x.size();i++) {
              Node* node = new Node(x[i]);
             mp[x[i]] = node;
          }
       }

       void Union(T x1,T x2) {
           Node* parent1 = findSet(mp[x1]);
           Node* parent2 = findSet(mp[x2]);

           if(parent1->rank >= parent2->rank) {
               if(parent1->rank == parent2->rank)
                    parent1->rank = parent1->rank+1;
                parent2->parent = parent1;
                parent2->rank = parent2->rank+1;
           }else {
                parent1->rank=parent1->rank+1;
                parent1->parent=parent2;
           }
       }

       T findSet(T data) {
           Node* node = findSet(mp[data]);
           return node->data;
       }
       Node* findSet(Node* node) {
           if(node->parent == node) {
               return node;
           }
           node->parent=findSet(node->parent);
           return node->parent;
       }
};

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    vector<int> v = {1,2,3,4};
    DisjointSet<int> s(v);
    
    s.Union(1,2);
    cout << s.findSet(2);
}