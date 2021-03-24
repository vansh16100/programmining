#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
//#include INF INT_MAX

int countPS(string str)
{
   int x = str.length();
   int dp[x][x];
   for(int l=0;l<x;l++) {
       int i=0;
       int j=l;
       while(j<x) {
           if(i==j) {dp[i][j]=1;j++;i++;continue;}
           if(i==j-1) {
               if(str[i]==str[j]) dp[i][j] = 3;
               else dp[i][j] = 2;
               i++;j++;
               continue;
           }
           if(str[i]==str[j]) {
               dp[i][j] = dp[i+1][j]+dp[i][j-1]+1;
           }else {
               dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
           }
           i++;j++;
       }
   }
   return dp[0][x-1];
}
void solve() {
   string s;
   cin>>s;
   cout<<countPS(s);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
