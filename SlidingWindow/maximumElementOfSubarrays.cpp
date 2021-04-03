#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
void solve() {
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++) {
      cin>>arr[i];
  }

  deque<int> q(k);
  int i=0;
  for(;i<k;i++) {
      while( !q.empty()&&arr[i]>arr[q.back()]) {
          q.pop_back();
      }
      q.push_back(i);
  }

  for(;i<n;i++) {
      cout<<arr[q.front()]<<" ";
      while(!q.empty()&&q.front()<=i-k) {
          q.pop_front();
      }
     while(!q.empty()&&arr[i]>arr[q.back()]) {
         q.pop_back();
     }
     q.push_back(i);

  }
  cout<<arr[q.front()];
}
int main() {
// #ifndef ONLINE_JUDGE
// freopen("E:/competitive/input.txt", "r", stdin);
// freopen("E:/competitive/output.txt", "w", stdout);
// #endif
// int t;
// cin>>t;
// while(t--){
solve();
 // }
return 0;
 }