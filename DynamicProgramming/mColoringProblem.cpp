#include <bits/stdc++.h>
using namespace std;

bool isSafe(bool graph[101][101],int v,int p,int m,int color[]) {
    for(int i=0;i<v;i++) {
        if(graph[p][i]==true) {
            if(color[i]==m) return false;
        }
    }
    return true;
}

bool dfs(int color[],bool graph[101][101],int m,int v,int root) {
    if(root==v) return true;
       for(int i=1;i<=m;i++) {
           if(isSafe(graph,v,root,i,color)) {
               color[root] = i;
               if(dfs(color,graph,m,v,root+1)) return true;
               color[root] = -1; 
           }
       }
       return false;
}
bool graphColoring(bool graph[101][101],int m,int v){
    int color[v];
    for(int i=0;i<v;i++) {
        color[i]=-1;
    }
       return dfs(color,graph,m,v,0);
    return true;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}