#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
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
void bellmanFord(unordered_map<int, list<GraphNode<int>>> &g,int v) {
    vector<pair<int, pair<int, int>>> edgeList;
    set<pair<int, int>> u;
    for (auto it : g)
    {
        for (auto adj : it.second)
        {
                edgeList.push_back(make_pair(adj.weight, make_pair(it.first, adj.key)));
        }
    }
     map<int,int> dist;
     map<int,int> path;
     for(auto it:g) {
         dist[it.first]=INT_MAX;
         path[it.first]=-1;
     }
     dist[0]=0;
     //edgeList<int,path>);
    for(int i=0;i<v;i++) {
        for(auto edge: edgeList) {
            auto t = edge.second;
            if(dist[t.first]!=INT_MAX) {
                if(dist[t.second] > dist[t.first]+edge.first ) {
                    dist[t.second] = dist[t.first]+ edge.first;
                    path[t.second] = t.first;
                }
            }
        }
    }
  cout<<endl;
    for(auto it: dist) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
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
        GraphNode<int> ny(y, weight);
        g[x].push_back(ny);
        // g[y].push_back(nx);
    }
    //  cout << prims(g, 0);
    // g.printGraph();
    for(auto it : g) {
        cout<<it.first<<"->";
        for(auto child:it.second) {
            cout<<"  "<<child.key<<","<<child.weight<<"   ";
        }
        cout<<endl;
    }
    bellmanFord(g,v);
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
solve();
return 0;
 }