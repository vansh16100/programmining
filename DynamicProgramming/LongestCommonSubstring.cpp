//   time complexity = O(length of string1 * length of string2)

#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;


int longestCommonSubstring(string s1,string s2) {
  int x=s1.length();
  int y=s2.length();
  int dp[x+1][y+1];

  for (int i = 0; i <= x; i++)
  {
    for (int j = 0; j <= y; j++)
    {
       if(i==0 || j==0) dp[i][j] = 0;
       else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
       else dp[i][j] = 0;
    }
  }

  int mx = 0;
  
  for (int i = 0; i <= x ; i++)
  {
    for(int j = 0; j <= y ; j++) 
    {
      mx=max( dp[i][j] , mx );
    }
  }
  return mx;
}
 void solve(){
  string s1,s2;
  cin>>s1>>s2;
  cout << longestCommonSubstring(s1,s2);
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
