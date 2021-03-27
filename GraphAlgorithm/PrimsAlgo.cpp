#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
template<typename T>
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
        nodePosition[key] = heap.size() - 1;

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
    int getWeight(T key)
    {
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
    bool empty()
    {
        return !(heap.size() > 0);
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
template <typename T>
class GraphNode
{
public:
    T key;
    int weight;
    GraphNode(T key, int weight)
    {
        this->key = key;
        this->weight = weight;
    }
};
int prims(unordered_map<int,list<GraphNode<int>>> graph,int root) {
    MinHeap<int> heap;
    for(auto it: graph ) {
        heap.add(INT_MAX,it.first);
    }
    heap.decreaseKey(root,0);
    unordered_map<int,pair<int,int>> in;
    vector<pair<int,int>> prim;
    int minWeight = 0;
    while(!heap.empty()) {
        auto node = heap.extractMin();
        if(node.key!=root) {
           // cout<<"hr;;p";
           minWeight+=node.weight;
           prim.push_back(in[node.key]);
        }
        //cout<<endl;
        for(auto it : graph[node.key]) {
           if(heap.checkKey(it.key)) {
               int w = heap.getWeight(it.key);
                if (w > it.weight)
                 { 
                    heap.decreaseKey(it.key,it.weight);
                    in[it.key]=make_pair(it.key,node.key);
                }
           }
        }
    }
    for(auto it:prim ) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return minWeight;

}
void solve()
{
    int v, e;
    cin >> v >> e;
    unordered_map<int, list<GraphNode<int>>> g;
    int x, y, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> weight;
        GraphNode<int> nx(x, weight);
        GraphNode<int> ny(y, weight);
        g[x].push_back(ny);
        g[y].push_back(nx);
    }
    cout<<prims(g,0);
   // g.printGraph();
    // for(auto it : g) {
    //     cout<<it.first<<"->";
    //     for(auto child:it.second) {
    //         cout<<"  "<<child.key<<","<<child.weight<<"   ";
    //     }
    //     cout<<endl;
    // }
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
solve();
return 0;
 }