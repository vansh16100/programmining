#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

class val
{ public:
  int first;
  int second;
};

bool myCmp(val v1,val v2) {
    return v1.first<v2.first;
}
int maxChainLen(val p[],int n)
{
//Your code here
  sort(p,p+n,myCmp);
  int sum=1;
  for(int i=1;i<n;i++) {
      if(p[i].first>p[0].second) {
         p[0].first=min(p[i].first,p[0].first);
         sum++;
          p[0].second=p[i].second;
      }
  }
  return sum;
}
 void solve(){
  int n;
  cin>>n;
   val arr[n];
  for(int i=0;i<n;i++) {cin>> arr[i].first >> arr[i].second;}
  cout<<maxChainLen(arr,n);
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
