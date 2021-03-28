#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#include<unordered_set>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
template <typename T>
class DisjointSet
{
    class Node
    {
    public:
        T data;
        int rank;
        Node *parent;
        Node(T data)
        {
            this->data = data;
            rank = 0;
            parent = this;
        }
    };
    unordered_map<T, Node *> mp;

public:
    DisjointSet(vector<int> x)
    {
        for (int i = 0; i < x.size(); i++)
        {
            Node *node = new Node(x[i]);
            mp[x[i]] = node;
        }
    }

    void Union(T x1, T x2)
    {
        Node *parent1 = findSet(mp[x1]);
        Node *parent2 = findSet(mp[x2]);

        if (parent1->rank >= parent2->rank)
        {
            if (parent1->rank == parent2->rank)
                parent1->rank = parent1->rank + 1;
            parent2->parent = parent1;
            parent2->rank = parent2->rank + 1;
        }
        else
        {
            parent1->rank = parent1->rank + 1;
            parent1->parent = parent2;
        }
    }

    T findSet(T data)
    {
        Node *node = findSet(mp[data]);
        return node->data;
    }
    Node *findSet(Node *node)
    {
        if (node->parent == node)
        {
            return node;
        }
        node->parent = findSet(node->parent);
        return node->parent;
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

int kruskal(unordered_map<int, list<GraphNode<int>>> &g) {
    vector<pair<int,pair<int,int>>> edgeList;
    set<pair<int,int>> u;
    for(auto it: g ) {
        for(auto adj : it.second ) {
            
            if(u.count(make_pair(it.first,adj.key )) == 0){
                edgeList.push_back(make_pair(adj.weight, make_pair(it.first, adj.key)));
                u.insert(make_pair(it.first, adj.key));
                u.insert(make_pair(adj.key, it.first));
            }
        }
    }
        vector<pair<int,int>> ans;
        int weight = 0;
        sort(edgeList.begin(),edgeList.end());
        vector<int> vertex(g.size());
        for(int i=0;i<g.size();i++) {
            cin>>vertex[i];
        }
        DisjointSet<int> disjointSet(vertex);
        
        for(auto it: edgeList) {
           auto pair = it.second;
           if(disjointSet.findSet(pair.first) != disjointSet.findSet(pair.second)) {
               disjointSet.Union(pair.first,pair.second);
               ans.push_back(make_pair(pair.first,pair.second));
               weight+=it.first;
           }
        }
    for(auto it : ans ) {
        cout<<it.first<<" "<<it.second<<endl;
    }

    return weight;

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
  //  cout << prims(g, 0);
    // g.printGraph();
    // for(auto it : g) {
    //     cout<<it.first<<"->";
    //     for(auto child:it.second) {
    //         cout<<"  "<<child.key<<","<<child.weight<<"   ";
    //     }
    //     cout<<endl;
    // }
    cout<<kruskal(g);
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
solve();
return 0;
 }