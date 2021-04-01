#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

vector<int> out;
stack<int> s;

void dfs(int v,vector<int> adj[],int root) {
  while(out[root]>0) {
      int nextEdge = adj[root].back();
      out[root]--;
      adj[root].pop_back();
      dfs(v,adj,nextEdge);
  }
 // cout<<"jk";
  s.push(root);
}
void solve() {
    int v, e;
    v = 7;
    e = 12;
    //     cin >> v >> e;
    vector<int> adj[v];
    //    //  cout<<e<<"L";
    //     for (int i = 0; i < e; i++)
    //     {    int x, y;
    //          cin >> x >> y;
    //          adj[x].push_back(y);
    //     }

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(2);
    adj[2].push_back(4);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(1);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[4].push_back(3);
    adj[5].push_back(6);
    adj[6].push_back(3);

    out.resize(v, 0);

    for (int i = 0; i < v; i++)
    {
        out[i] = adj[i].size();
    }
     dfs(v,adj,1);
   
     while(!s.empty()) {
         cout<<s.top()<<" ";
         s.pop();
     }
}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
solve();
return 0;
 }