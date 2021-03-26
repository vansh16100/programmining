#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

class Graph{
private:
  int v;
  int **arr;
public:
  Graph(int v) {
    this->v=v;
    arr = new int*[v];
    for(int i=0;i<v;i++) {
        arr[i] = new int[v];
    }
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            arr[i][j]=0;
        }
    }
  }
 
  void addEdge(int u,int v) {
      arr[u][v]=1;
      arr[v][u]=1;
  }
  void deleteEdge(int u,int v) {
      arr[u][v]=0;
      arr[v][u]=0;
  }
  vector<int> bfs(int root) {
      bool visited[v];
      memset(visited,false,sizeof(visited));
      vector<int> bfsVector;
      queue<int> q;
      q.push(root);
      visited[root] = true;
      while(!q.empty()) {
         auto front = q.front();
         bfsVector.push_back(front);
         q.pop();
         for(int i=0;i<v;i++) {
             if(arr[front][i]==1&&(!visited[i])) {
                 q.push(i);
                 visited[i]=true;
             }
         }
      }
      return bfsVector;
  }
};
void solve() {
    int v,e;
    cin>>v>>e;
    Graph graph(v);
    int x,y;
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        graph.addEdge(x,y);
    }

    vector<int> bfsVector;
    bfsVector = graph.bfs(0);
    for(int i=0;i<bfsVector.size();i++) {
        cout<<bfsVector[i]<<", ";
    }
    cout<<"\n";

}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
solve();
return 0;
 }
