#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
template<typename T>
class Graph{
public:
  int v;
  vector<T> vertices;
  map<T,list<T>> graph;
public:
  Graph(int v,vector<T> vertex) {
      this->v=v;
      for(int i=0;i<vertex.size();i++) {
          vertices.push_back(vertex[i]);
      }
      
  }

  void addEdge(T u,T v) {
     graph[u].push_back(v);
     graph[v].push_back(u);
  }
  vector<T> dfsUtil(T root,unordered_map<T,bool> &visited) {
      visited[root] = true;
     
      vector<T> dfsVector;
     
      for(auto child:graph[root]) {
          if(!visited[child]) {
              vector<T> v;
              visited[child]=true;
              v =  dfsUtil(child,visited);
              for(int i=0;i<v.size();i++) {
                  dfsVector.push_back(v[i]);
              }
          }
      }
      dfsVector.push_back(root);
      return dfsVector;
  }
  vector<vector<T>> dfs(T root) {
      unordered_map<T,bool> visited;
      for(auto it : graph) {
          visited[it.first] = false;
      }
      vector<vector<T>> dfsVector;
      vector<T> v;
      for(int i=0;i<vertices.size();i++) {
          if(!visited[vertices[i]]){
          dfsVector.push_back(dfsUtil(vertices[i],visited));
        }
      }
      return dfsVector;
  }
void printGraph() {
    for(auto it:graph) {
        cout<<it.first<<"->";
        for(auto child:it.second) {
            cout<<child<<" ";
        }
        cout<<endl;
    }
}
 
};
bool hasCycle(map<int,list<int>> adj,int V,int root,int parent,bool tmpVisited[],bool visited[]) {
    visited[root] = true;
    tmpVisited[root] = true;
    for (auto i:adj[root])
    {  
        if (i == root)
            return true;
        if (tmpVisited[i] && i != parent)
        {
            return true;
        }
        if ((!tmpVisited[i]) && hasCycle(adj, V , i, root, tmpVisited, visited))
        {
            return true;
        }
       
    return false;
  }
}
bool isCycle(int V,Graph<int> *g) {
   auto map = g->graph;
   auto vertex = g->vertices;
   for(auto it:map) {
       cout<<it.first<<"->";
       for(auto i:it.second) {
          cout<<i<<" ";
       }
       cout<<endl;
   }
   bool visited[V];
   bool tmpVisited[V];
   for (int i = 0; i < V; i++)
       tmpVisited[i] = false;
   memset(visited, false, sizeof(visited));
   for (int i = 0; i < V; i++)
   {
       if (!visited[i])
       {
           bool hCycle  = hasCycle(map,V,i,-1,tmpVisited,visited);
           if (hCycle)
               return true;
           for(int i=0;i<V;i++) tmpVisited[i]=false;
       }
   }
   return false;
}
void solve() {
    int v,e;
    cin>>v>>e;
    
    int x,y;
    vector<int> vertex(v);
    for(int i=0;i<v;i++) {
       cin>>vertex[i];
    }
    Graph<int> graph(v,vertex);
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        graph.addEdge(x,y);
    }
   cout<<"hello";
   cout<<isCycle(v,&graph);
}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
solve();
return 0;
 }