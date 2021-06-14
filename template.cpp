#include <bits/stdc++.h>
using namespace std;
using v_i=vector<int>;
#define ll long long int
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

struct custom_hash {
 
      static uint64_t splitmix64(uint64_t x) {
         x += 0x9e3779b97f4a7c15;
         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
     size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void solve() {
 
}
 
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
     }
    return 0;
 }