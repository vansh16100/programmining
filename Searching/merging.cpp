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
   int n;
   cin>>n;
   pii arr[n];
   for(auto &it : arr) {
       cin>>it.first;
       cin>>it.second;
   }
   pii interval;
   cin>>interval.first>>interval.second;
   int i;
   for(i=0; i<n; i++) {
       if(arr[i].first >= interval.first) {
           break;
       }
   }
   vector<pii> merged;
   int pos=i;
   for(int i=0; i<n+1; i++) {
       pii p={-1,-1};
       if(pos==i) {
           p=interval;
           i--;
           pos=-1;
       }else if(i!=n) p=arr[i];
       if(p!=make_pair(-1,-1)&&i==0) merged.push_back(p);
       else if (p != make_pair(-1, -1) ) {
           auto &x = merged.back();
           if(x.second >= p.first)  {
               x.second = max(x.second,p.second);
           }
           else  {
               merged.push_back(p);
           }
       }
   }
   for(auto it:merged) {
       cout<<it.first<<" "<<it.second<<"\n";
   }
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