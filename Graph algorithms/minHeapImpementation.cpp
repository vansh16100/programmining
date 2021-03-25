#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

template<typename T>
class MinHeap {
   class Node {
       public:
         T key;
         int weight;
        Node(T key,int weight) {
          this->key = key;
          this->weight = weight;
        }
   };
   unordered_map<T,int> nodePosition;
   vector<Node> heap;
public:
   void heapify(int pos) {
       int leftChild = 2*pos+1;
       int rightChild = 2*pos+2;
       int min = pos;
       int n=heap.size();
       if(leftChild < n && heap[min].weight>heap[leftChild].weight) {
           min=leftChild;
       } 
       if(rightChild < n && heap[min].weight > heap[rightChild].weight ) {
           min=rightChild;
       }
       if(min!=pos) {
           swap(heap[pos],heap[min]);
           changePos(heap[pos],heap[min],pos,min);
           heapify(min);
       }
   }
   void add(int weight,T key) {
       Node node(key,weight);
       heap.push_back(node);
       nodePosition[key] = heap.size();
       
       int i=heap.size()-1;
       while(i>0) {
           int parent = (i-1)/2;
           if(heap[parent].weight > heap[i].weight) {
               swap(heap[i],heap[parent]);
               changePos(heap[i],heap[parent],i,parent);
           }
           i=parent;
       }
   }
   
   Node extractMin() {
      Node min = heap[0];
      swap(heap[0],heap[heap.size()-1]);
      changePos(heap[0],heap[heap.size()-1],0,heap.size()-1);
      nodePosition.erase(heap[heap.size()-1].key);
      heap.pop_back();
      heapify(0);
      return min.key;
   }
   void changePos(Node n1, Node n2, int i, int parent)
   {
       nodePosition.erase(n1.key);
       nodePosition.erase(n2.key);
       nodePosition[n1.key] = i;
       nodePosition[n2.key] = parent;
   }
   bool checkKey(T key) {
       if(nodePosition.count(key) > 0) return true;
       return false;
   }
   void decreaseKey(T key , int weight) {
       int pos = nodePosition[key];
       heap[pos].weight = weight;
      // heapify(pos);
       int i = pos;
       while (i > 0)
       {
           int parent = (i - 1) / 2;
           if (heap[parent].weight > heap[i].weight)
           {
               swap(heap[i], heap[parent]);
               changePos(heap[i], heap[parent], i, parent);
           }
           i = parent;
       }
   }
   void print() {
       for(int i=0;i<heap.size();i++) {
           cout<<heap[i].key<<" ";
       }
       cout<<endl;
       for(auto it:nodePosition) {
           cout<<it.first<<" ";
           cout<<it.second<<" ";
           cout << endl;
       }
      
   }
};

void solve() {
   MinHeap<int> h;
   h.add(5,0);
   h.add(3,1);
   h.add(2,2);
   h.add(1,3);
   h.add(0,4);
  auto key = h.extractMin();
  h.decreaseKey(0,0);
   //cout<<key<<endl;
  // cout<<h.checkKey(4)<<endl;
   h.print();
}


int main() {
#ifndef true
    freopen("E:/competitive/input.txt", "r", stdin);
    freopen("E:/competitive/output.txt", "w", stdout);
#endif
solve();
return 0;
 }