#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct triplet{
    int gcd,x,y;
    triplet(int gcd,int x,int y): gcd(gcd),x(x),y(y) {}
    triplet(){}
};
 
triplet extendedEuclid(int a,int b) {
    if(b==0) {
        return *new triplet(a,1,0);
    }
    triplet recAns = extendedEuclid(b,a%b);

    return *new triplet(recAns.gcd,recAns.y,recAns.x - (a/b)*recAns.y); 
    
}
int main() {
   int a,b;
   cin >> a >> b;
   triplet ans = extendedEuclid(a,b);
   cout << ans.gcd << ' ';
   cout << ans.x << ' ' << ans.y;
   return 0;
 }