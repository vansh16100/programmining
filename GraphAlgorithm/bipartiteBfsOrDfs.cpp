#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#define ll long long int
#define pii pair<int, int>
#define pic pair<int, char>
using namespace std;
using v_i = vector<int>;
bool check_cycle_oddBfs(int V,vector<int> adj[],int visited[],int root){
       
      visited[root]=1;
      queue<pair<int,int>> q;
      q.push(make_pair(root,1));
      while(!q.empty()){
          auto remov = q.front();
          q.pop();
          if(visited[remov.first]!=0){
              if(remov.second!=visited[remov.first])
                     return true;
          }
          visited[remov.first]=remov.second;
          for(auto it: adj[remov.first]){
              if(visited[it]==0){
                  q.push(make_pair(it,remov.second+1));
              }
          }
      }
      return false;
}
bool check_cycle_oddDfs(int V, vector<int> adj[], int visited[], int root, int parent, bool recur_stack[], int cycle_length)
{
    visited[root] = cycle_length;
    recur_stack[root] = true;
    for (auto it : adj[root])
    {
        if (recur_stack[it] && it != parent && (cycle_length - visited[it] + 1) % 2 != 0)
        {
            return true;
        }
        else if (!visited[it] && check_cycle_oddDfs(V, adj, visited, it, root, recur_stack, cycle_length + 1))
            return true;
    }
    recur_stack[root] = false;
    return false;
}
 bool isBipartite(int V, vector<int> adj[]) {
        // Code here
        int visited[V];
        bool recur_stack[V];
        unordered_map<int, int> level;
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            recur_stack[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (check_cycle_oddDfs(V, adj, visited, i, -1, recur_stack, 1))   //WE can call any of the functions.
                    return false;
            }
        }
        return true;
}
void solve()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << isBipartite(v, adj);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}