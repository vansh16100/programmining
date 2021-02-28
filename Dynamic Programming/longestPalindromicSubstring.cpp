
#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int longestPalindromicSubstring(string s) {
     int x=s.length();
     int dp[x][x];
     for(int i=0;i<x;i++) {
      dp[i][i]=1;
      if(i<x-1&&s[i]==s[i+1]) dp[i][i+1] = 1;
      else if(i<x-1) dp[i][i+1] = 0;
     }

     for(int g=2;g<x;g++) {
      int i=0;
      int j=g;
      while(j<x) {
        if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] || 0;
        else dp[i][j] = 0;
        i++;j++;
      }
     }
   
   for(int g=x-1;g>=0;g--) {
      int i=0;
      int j=g;
      while(j<x) {
        if(dp[i][j]==1) return g+1;  //g+1 is telling the the length of substring
        i++;j++;
      }
   }
  
}
void solve() {
   string s;
   cin>>s;
   // if we fave to find the no of palindromic
   // substring then just the count the no of ones in the dp array
   //such tha i<=j; because we are doing it with the gap strategy
   int maximumPalindromicSubstringLength = longestPalindromicSubstring(s);
   cout<<maximumPalindromicSubstringLength;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
