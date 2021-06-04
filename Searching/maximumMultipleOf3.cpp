#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
 
//debug
#define deb(x) cout<<#x<<" = "<<x
#define deb_s(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define deb3(x, y,z) cout << #x << "=" << x << " " << #y << "=" << y<<" "<<#z<<"="<<z<<endl
 
 inline void file() {
     #ifndef ONLINE_JUDGE
        freopen("e:/competitive/input.txt", "r", stdin);
        freopen("e:/competitive/output.txt", "w", stdout);
     #endif
}
 
void solve() {
    int n; cin>>n;
   vector<int> v(n) ;
   for(int i=0; i<n; i++) cin>>v[i];
   
   int count[10] = {0};
   
   for(int i=0; i<n; i++) count[v[i]]++;
   int k=0;
   for(int i=9; i>=0; i--) {
       while(count[i]>0) {
           v[k++]=i;
           count[i]--;
       }
   }

   int two1,two2,one1,one2;
   two1=two2=one1=one2=-1;
   int sum=0;
   for(int i=0; i<n; i++) {
       sum += v[i];
       sum %= 3;
       if(v[i] %3==1) {
          one2=one1;
          one1=v[i];
       }if(v[i]%3==2) {
          two2=two1;
          two1=v[i];
       }
   }
  int removed1=-1,removed2=-1;
  if(sum==1) {
      if(one1!=-1) removed1 = one1;
      else removed1 = two1 , removed2 = two2;
  }
  if(sum==2) {
     if(two1!=-1) removed1 = two1;
     else removed1 = two1 , removed2 = two2;
  }
  for(int i=0; i<n; i++) {
      if(removed1 == v[i]) {
          removed1=-1;
          continue;
      }
      if(removed2==v[i]) {
          removed2=-1;
          continue;
      }

      cout<<v[i];
  }
  cout<<"\n";
}
 
int main() {
    file();
int t;
cin>>t;
while(t--){
solve();
  }
return 0;
 }