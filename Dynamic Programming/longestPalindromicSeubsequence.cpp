
#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int longestPalindromeSubseq(string s) {
    int x=s.length();
    int dp[x][x];
    for(int i=0;i<x;i++) {
        dp[i][i] = 1;
        if(i<x-1&&s[i]==s[i+1]) dp[i][i+1]=2;
        else if(i<x-1) dp[i][i+1]=1;
    }
    
    for(int g=2;g<x;g++) {
        int i=0;
        int j=g;
        while(j<x) {
            if(s[i]==s[j]) dp[i][j] = 2+dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j],max(dp[i][j-1],dp[i+1][j-1]));
            i++;j++;
        }
    }
    return dp[0][x-1];
}
void solve() {
   string s;
   cin>>s;
   cout<<longestPalindromeSubseq(s);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
