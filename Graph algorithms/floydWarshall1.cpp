// this algo will only tells us the minimum distance matrix between every pair of vertices
// O(V^3)
//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
//#include INF INT_MAX


void floydWarshall(vector<v_i> adjacencyMatrix,int V) {
    int minimumDistanceMatrix[V][V];
    int i=0,j=0;
    for(i=0;i<V;i++) {
       for(j=0;j<V;j++) {
          int initialDistance = 10000000;  //refer to as INF
          if(i == j) initialDistance = 0;
          else initialDistance = adjacencyMatrix[i][j];
          minimumDistanceMatrix[i][j] = initialDistance;
       }
    }
   
    for(int k = 0 ; k < V ; k++) {
         for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                  if(minimumDistanceMatrix[i][j] > minimumDistanceMatrix[i][k] + minimumDistanceMatrix[k][j])
                     minimumDistanceMatrix[i][j] = minimumDistanceMatrix[i][k] + minimumDistanceMatrix[k][j];
            }
         }
    }
     for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                  if(minimumDistanceMatrix[i][j] == 10000000) cout<<"INF ";
                  else cout<<minimumDistanceMatrix[i][j]<<" ";
          }
            cout<<"\n";
      }
}
void solve() {
   int v;
   cin>>v;

   vector<v_i> adjacencyMatrix(v);
   for(int i=0;i<v;i++) {
      for(int j=0;j<v;j++) {
        int x;
        cin>>x;
        adjacencyMatrix[i].push_back(x);     //take 10^7 as infinity
      }
   }
  
   floydWarshall(adjacencyMatrix,v);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
