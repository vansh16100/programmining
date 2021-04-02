#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
void solve() {
   int v;
   cin>>v;
   int arr[v][v];
   for(int i=0;i<v;i++) {
       for(int j=0;j<v;j++) {
           cin>>arr[i][j];
       }
   }
  int count=0;
   for(int k=0;k<v;k++) {
       for(int i=0;i<v;i++) {
           for(int j=0;j<v;j++) {
               if(arr[k][i]>0&&arr[i][j]>0&&arr[j][k]>0) count++;
           }
       }
   }
   cout<<count/3;
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
solve();
return 0;
 }