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
private:
  int v;
  map<T,list<T>> graph;
public:
  Graph(int v) {
      this->v=v;
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
  vector<T> dfs(T root) {
      unordered_map<T,bool> visited;
      for(auto it : graph) {
          visited[it.first] = false;
      }
      vector<T> dfsVector;
      dfsVector = dfsUtil(root,visited);
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
void solve() {
    int v,e;
    cin>>v>>e;
    Graph<int> graph(v);
    int x,y;
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        graph.addEdge(x,y);
    }

    vector<int> bfsVector;
    bfsVector = graph.dfs(0);
    for(int i=0;i<bfsVector.size();i++) {
        cout<<bfsVector[i]<<", ";
    }
    cout<<"\n";
   // graph.printGraph();

}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
solve();
return 0;
 }
