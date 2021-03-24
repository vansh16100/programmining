// time complexity = O(m*n)
// space = O(m*n)


#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
//#include INF INT_MAX


int longestCommonSubsequence(string s1,string s2) {
  int x=s1.length();
  int y=s2.length();
  int dp[x+1][y+1];
  for(int i=0;i<=x;i++) {
    for(int j=0;j<=y;j++) {
      dp[i][j]=0;
    }
  }

  for(int i=1;i<=x;i++) {
    for(int j=1;j<=y;j++) {
      if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
    }
  }
  return dp[x][y];
}

void solve() {
   string s1,s2;
   cin>>s1>>s2;
   cout<<longestCommonSubsequence(s1,s2);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
