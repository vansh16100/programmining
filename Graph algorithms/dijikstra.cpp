#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i = vector<int>;
template <typename T>
class MinHeap
{
    class Node
    {
    public:
        T key;
        int weight;
        Node(T key, int weight)
        {
            this->key = key;
            this->weight = weight;
        }
    };
    unordered_map<T, int> nodePosition;
    vector<Node> heap;

public:
    void heapify(int pos)
    {
        int leftChild = 2 * pos + 1;
        int rightChild = 2 * pos + 2;
        int min = pos;
        int n = heap.size();
        if (leftChild < n && heap[min].weight > heap[leftChild].weight)
        {
            min = leftChild;
        }
        if (rightChild < n && heap[min].weight > heap[rightChild].weight)
        {
            min = rightChild;
        }
        if (min != pos)
        {
            swap(heap[pos], heap[min]);
            changePos(heap[pos], heap[min], pos, min);
            heapify(min);
        }
    }
    void add(int weight, T key)
    {
        Node node(key, weight);
        heap.push_back(node);
        nodePosition[key] = heap.size()-1;

        int i = heap.size() - 1;
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

    Node extractMin()
    {
        Node min = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        changePos(heap[0], heap[heap.size() - 1], 0, heap.size() - 1);
        nodePosition.erase(heap[heap.size() - 1].key);
        heap.pop_back();
        heapify(0);
        return min;
    }
    void changePos(Node n1, Node n2, int i, int parent)
    {
        nodePosition.erase(n1.key);
        nodePosition.erase(n2.key);
        nodePosition[n1.key] = i;
        nodePosition[n2.key] = parent;
    }
    bool checkKey(T key)
    {
        if (nodePosition.count(key) > 0)
            return true;
        return false;
    }
    int getWeight(T key) {
        return heap[nodePosition[key]].weight;
    }
    void decreaseKey(T key, int weight)
    {  
        int pos = nodePosition[key];
        heap[pos].weight = weight;
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
    bool empty() {
         return !(heap.size() > 0) ; 
    }
    void print()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i].key << " ";
        }
        cout << endl;
        for (auto it : nodePosition)
        {
            cout << it.first << " ";
            cout << it.second << " ";
            cout << endl;
        }
    }
};
template<typename T>
class GraphNode {
    public:
     T key;
     int weight;
     GraphNode(T key,int weight) {
         this->key = key;
         this->weight = weight;
     }
};

unordered_map<int,int> dijikstra(unordered_map<int,list<GraphNode<int>>> graph, int root) {
    unordered_map<int,int> dist;
    unordered_map<int,int> parent;
    MinHeap<int> heap;

    for(auto it : graph) {
        dist[it.first] = INT_MAX;
        parent[it.first] = -1;
        heap.add(INT_MAX,it.first);
    }
   // heap.print();
    heap.decreaseKey(root,0);
   
while(!heap.empty()) {
   auto minDisNode = heap.extractMin();
   int key = minDisNode.key;
   int weight = minDisNode.weight;
   dist[key] = weight;
   for(auto it:graph[key]) {
       if(heap.checkKey(it.key)) {
           int heapWeight = heap.getWeight(it.key);
           if(heapWeight==INT_MAX)
           {
               heap.decreaseKey(it.key, dist[key] + it.weight);
               parent[it.key] = key;
           }
           else if(heapWeight > dist[key] + it.weight){
               heap.decreaseKey(it.key, dist[key] + it.weight);
               parent[it.key] = key;
             }
       }
   }

}
  for(auto it : parent) {
      cout<<it.first<<" "<<it.second<<" "<<endl;
  }
  cout<<endl;
   return dist;
}
void solve() {
    int v,e;
    cin>>v>>e;
   unordered_map<int,list<GraphNode<int>>> g;
    int x,y,weight;
     for(int i=0;i<e;i++) {
        cin>>x>>y>>weight;
        GraphNode<int> nx(x,weight);
        GraphNode<int> ny(y,weight);
        g[x].push_back(ny);
        g[y].push_back(nx);
    }
   // g.printGraph();
    // for(auto it : g) {
    //     cout<<it.first<<"->";
    //     for(auto child:it.second) {
    //         cout<<"  "<<child.key<<","<<child.weight<<"   ";
    //     }
    //     cout<<endl;
    // }
    auto dist = dijikstra(g,1);
    for(auto it: dist) {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("E:/competitive/input.txt", "r", stdin);
//     freopen("E:/competitive/output.txt", "w", stdout);
// #endif
solve();
return 0;
 }