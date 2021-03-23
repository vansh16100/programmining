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
  vector<T> bfs(T root) {
      unordered_map<T,bool> visited;
      for(auto it : graph) {
          visited[it.first] = false;
      }
      vector<T> bfsVector;
      queue<T> q;
      q.push(root);
      visited[root]=true;
      while(!q.empty()) {
          T front = q.front();
          bfsVector.push_back(front);
          q.pop();
          for(auto child: graph[front]) {
                  if(!visited[child]) {
                      visited[child] = true;
                      q.push(child);
                  }
            
          }
      }
      return bfsVector;
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
    Graph<string> graph(v);
    string x,y;
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        graph.addEdge(x,y);
    }

    vector<string> bfsVector;
    bfsVector = graph.bfs("vansh");
    for(int i=0;i<bfsVector.size();i++) {
        cout<<bfsVector[i]<<", ";
    }
    cout<<"\n";
  //  graph.printGraph();

}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
solve();
return 0;
 }
