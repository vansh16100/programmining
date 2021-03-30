#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
#define INF -1000000
void dfs(vector<pair<int,int>> adj[], int v, stack<int> &s, int root, bool visited[])
{
    visited[root] = true;

    for (auto it : adj[root])
    {
        if (!visited[it.first])
        {
            dfs(adj, v, s, it.first, visited);
        }
    }
    s.push(root);
}

void reset(bool a[], int v)
{
    for (int i = 0; i < v; i++)
    {
        a[i] = false;
    }
}
void longestPath(vector<pair<int,int>> adj[],int v) {
    for(int i=0;i<v;i++) {
        for(auto it: adj[i]) {
            it.second=-1*it.second;
        }
    }
    stack<int> s;
    bool visited[v];
    reset(visited, v);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(adj, v, s, i, visited);
        }
    }
    int distance[v];
    for(int i=0;i<v;i++) {
        distance[i] = INF;
    }
    distance[1]=0;
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        if(distance[top]!=INF){
        for(auto it:adj[top]) {
            if(distance[top] + it.second > distance[it.first] ) {
                 distance[it.first] = distance[top] + it.second;
            }
        }
        }
    }
    for(int i=0;i<v;i++) {
        distance[i]==INF?cout<<"INF ":cout<<distance[i]<<" ";
    }
}
void solve() {
    int v, e;
    cin >> v >> e;
    vector<pair<int,int>> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y ,w;
        cin >> x >> y>>w;
        adj[x].push_back({y,w});
    }
    longestPath(adj,v);
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
solve();
return 0;
 }