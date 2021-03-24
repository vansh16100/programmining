//time complexity = O(n^2)
// this algorithm tells the not of sentences i can make with the given string using the dictionary given

#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
//#include INF INT_MAX
bool isFind(string A,vector<string> B) {
  int len = B.size();
  for(int i=0;i<len;i++) {
    if(A==B[i]) return true;
  }
  return false;
}
int wordBreak(string A,vector<string> &B) {
   int l = A.length();
   int dp[l+1];
   dp[0] = 1;
   for(int i=1;i<=l;i++) {
     dp[i] = 0;
       for(int j=0;j<i;j++) {
        string temp = A.substr(j,i-j);
        if(isFind(temp,B)) {
          dp[i] += dp[j];
        }
       }
   }
   return dp[l];
}
void solve() {
   string A;
   cin>>A;
   int dictSize;
   cin>>dictSize;
   vector<string> dictionary(dictSize);
   for(int i=0;i<dictSize;i++) {
    cin >> dictionary[i];
   }
   cout << wordBreak(A,dictionary);
}
int main() {
    // int t;
    // cin>>t;
    // while(t--){
        solve();
//    }
    return 0;
}
