  //complexity = o(n*m)  i.e the size of a matrix

#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int maxSquare(int n, int m, vector<vector<int>> mat){
        int dp[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0||j==0) dp[i][j]=mat[i][j];
                else if(mat[i][j]==0) dp[i][j]=0;
                else {
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                mx=max(mx,dp[i][j]);
            }
        }
        return mx;
 }

 void solve(){
  int n,m;
  cin>>n>>m;
   vector<vector<int>> mat(n);
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      int x;
      cin>>x;
      mat[i].push_back(x);
    }
  }
  cout<<maxSquare(n,m,mat);
}


int main() {
   // your code goes here
    // int t;
    // cin>>t;
    // while(t--){
        solve();
  // }
    return 0;
}
