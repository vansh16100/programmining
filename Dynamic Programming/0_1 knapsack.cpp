#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int knapSack(int W, int weight[], int arr[], int n) 
{ 
   int dp[n+1][W+1];
   for(int i=0;i<=n;i++) {
    for(int j=0;j<=W;j++) {
      dp[i][j] = 0 ;
    }
   }
   for(int i=1;i<=n;i++) {
    for(int j=1;j<=W;j++) {
      int res=INT_MIN;
      if(weight[i-1]<=j) res = dp[i-1][j-weight[i-1]];
      if(res!=INT_MIN) dp[i][j]=max(res+arr[i-1],dp[i-1][j]);
      else dp[i][j]=dp[i-1][j];
    }
   }
   return dp[n][W];
}

void solve(){
   int n,w;
   cin>>n>>w;
   int weight[n],value[n];
   for(int i=0;i<n;i++) cin>>value[i];
   for(int i=0;i<n;i++) cin>>weight[i];
    cout<<knapSack(w,weight,value,n);
}


int main() {
    // your code goes here
        solve();
    return 0;
}
