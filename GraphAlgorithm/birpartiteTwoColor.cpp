#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

bool twoColor(int color[],vector<int> adj[],int v,int root) {
    color[root]=1;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto it:adj[front]) {
            if(color[it]==-1) {
                color[it]=1-color[front];
                q.push(it);
            }else{
                if(color[it]==color[front]) return false;
            }
        }
    }
    return true;
}
bool isBipartite(int v,vector<int> adj[]) {
    int color[v];
    memset(color,-1,sizeof(color));
    for(int i=0;i<v;i++) {
        if(color[i]==-1) {
          if(!twoColor(color,adj,v,i)) return false;
        }
    }
  return true;
}
void solve() {
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
    cout<<isBipartite(v,adj);

}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

solve();
return 0;
 }