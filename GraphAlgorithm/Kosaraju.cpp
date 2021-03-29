#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
void dfs(vector<int> adj[],int v,stack<int> &s,int root,bool visited[]) {
    visited[root]=true;

    for(auto it : adj[root]) {
        if(!visited[it]) {
            dfs(adj,v,s,it,visited);
        }
    }
    s.push(root);
}
void reset(bool a[],int v) {
    for(int i=0;i<v;i++) {
        a[i]=false;
    }
}

void transpose(vector<int> trans[],vector<int> adj[],int v) {
   for(int i=0;i<v;i++) {
       for(auto it: adj[i]) {
           trans[it].push_back(i);
       }
   }
}

int kosaraju(vector<int> adj[] ,int v) {
   stack<int> s,notUsed;
   bool visited[v];
   reset(visited,v);
   for(int i=0;i<v;i++) {
       if(!visited[i]) {
           dfs(adj,v,s,i,visited);
       }
   }
 vector<int> trans[v];
 transpose(trans,adj,v);
 reset(visited,v);
 int count=0;
 while(!s.empty()) {
     int x=s.top();
     s.pop();
     if(visited[x]) continue;
     dfs(trans,v,notUsed,x,visited);
     count++; 
 }
 return count;
}

void solve() {
    int v,e;
    cin>>v>>e;
  vector<int> adj[v];
  for(int i=0;i<e;i++) {
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
  }
 cout<< kosaraju(adj,v);
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
solve();
return 0;
 }