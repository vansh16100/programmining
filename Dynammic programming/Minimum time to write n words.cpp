// O(n)
// this algorithm tells the minimum time to write the N words using the operations  Insertion,Copying,Deletion.
#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;


int minTimeForWritingChars(int N, int I, int D, int C) 
  { 
      int dp[N+1] = {0};
      dp[1] = I; 
      for(int i=2;i<=N;i++) {
          if((i&1)==0) {
              dp[i] = min( dp[i-1]+I , dp[i/2]+C );
          }else {
              dp[i] = min( dp[i-1]+I , dp[(i+1)/2]+C+D);
          }
      }
      return dp[N];
  } 
 void solve(){
  int n,i,d,c;
  cin>>n>>i>>d>>c;
  cout << minTimeForWritingChars(n,i,d,c);
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
