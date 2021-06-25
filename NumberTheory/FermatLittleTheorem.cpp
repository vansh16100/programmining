#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll MOD = 998244353;
ll fastPower(ll a,ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b%2 != 0) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ans;
}
ll inverse(int a) {
    return fastPower((ll)a,(ll)MOD-2)%MOD;
}
int main() {
   int a;
   cin >> a;
   cout << inverse((ll)a);
   return 0;
 }