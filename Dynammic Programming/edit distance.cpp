//memoised solution
//O(m*n)
#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int memo[101][101];
int editDistance1(string s,string t,int x,int y) {
    if(memo[x][y]!=-1) return memo[x][y];
    if(x==0) {memo[x][y]=y;return y;}
    if(y==0) {memo[x][y]=x;return x;}
    if(s[x-1]==t[y-1]) memo[x][y]=editDistance1(s,t,x-1,y-1);
    else {
        memo[x][y]=1+min(editDistance1(s,t,x-1,y-1),min(editDistance1(s,t,x-1,y),editDistance1(s,t,x,y-1)));
    }
    return memo[x][y];
}
void reset(int x,int y) {
    for(int i=0;i<=x;i++) {
        for(int j=0;j<=y;j++)
            memo[i][j]=-1;
    }
} 
void print(int x,int y) {
     for(int i=0;i<=x;i++) {
        for(int j=0;j<=y;j++)
            cout<<memo[i][j]<<" ";
            cout<<endl;
    }
}

 void solve(){
   string s,t;
   cin>>s>>t;
   reset(s.length(),t.length());
   cout<<editDistance1(s,t,s.length(),t.length());
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
