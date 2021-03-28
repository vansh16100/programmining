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
void floydWarshall(unordered_map<int, list<GraphNode<int>>> &g,int v) {
   vector<vector<int>> dist(v+1,vector<int>(v+1,INT_MAX));
   for(auto it: g){
       for (auto i: g[it.first]) {
           dist[it.first][i.key]=i.weight;
       }
       dist[it.first][it.first]=0;
   }
   vector<vector<int>> path(v + 1, vector<int>(v + 1, -1));
   for(int k=1;k<=4;k++){
       for(int i=1;i<=4;i++) {
           for(int j=1;j<=4;j++) {
               if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX) {
                   dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                   path[i][j]=path[k][j];
               }
           }
       }
   }

   for(int i=1;i<=4;i++) {
       for(int j=1;j<=4;j++) {
           cout<<dist[i][j]<<" ";
       }
       cout<<endl;
   }
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
        // g[y].push_back(nx);
    }
    // g.printGraph();
    // for(auto it : g) {
    //     cout<<it.first<<"->";
    //     for(auto child:it.second) {
    //         cout<<"  "<<child.key<<","<<child.weight<<"   ";
    //     }
    //     cout<<endl;
    // }
    floydWarshall(g,v);
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

solve();
return 0;
 }