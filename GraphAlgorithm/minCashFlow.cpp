#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
int minCost(vector<int> arr) {
    int v=arr.size();
    int min_cost=INT_MAX,pos;
    for (int i = 0; i < v; i++)
    {
        if (min_cost > arr[i])
        {
            min_cost = arr[i];
            pos = i;
        }
    }
    return pos;
}
int maxCost(vector<int> arr) {
    int v=arr.size();
    int max_cost=INT_MIN,pos=0;
    for(int i=0 ; i<v;i++) {
        if(max_cost<arr[i]) {
            max_cost = arr[i];
            pos=i;
        }
    }
    return pos;
}

void minFlow(vector<int> &cost) {
  //  cout<<"jhf";
    int maxCreditPos = maxCost(cost);
    int maxDebtPos = minCost(cost);
    if(cost[maxCreditPos]==0&&cost[maxDebtPos]==0) return;
    int x = min(abs(cost[maxCreditPos]),abs(cost[maxDebtPos]));

    cout<<"give money "<<x<<" from "<<maxDebtPos<<" to "<<maxCreditPos<<endl;

    cost[maxCreditPos] -= x;
    cost[maxDebtPos] += x;

    minFlow(cost);

}
void solve() {
    int v,e;
    cin>>v>>e;
    //cout<<"fh";
  list<pair<int,int>> graph[v];
  for(int i=0;i<e;i++) {
    int x,y,w;
    cin>>x>>y>>w;
    graph[x].push_back(make_pair(y,w));
  }
  vector<int> cost(v,0);
  for(int i=0;i<v;i++) {
      for(auto it : graph[i]) {
          cost[i] -= it.second;
          cost[it.first] += it.second;
      }
  }
  minFlow(cost);
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
solve();
return 0;
 }