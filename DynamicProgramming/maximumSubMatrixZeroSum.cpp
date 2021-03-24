#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int maximumSubArrayZeroSum(vector<int> A,int n,int&st,int &en) {
	map<int,int> prefix;
    int len=0;
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=A[i];
        if(A[i]==0&&len==0) {
            len=1;
            st=i,en=i;
        }
        if(sum==0) {
            st=0;
            en=i;
            len=i+1;
        }
        if(prefix.find(sum)!=prefix.end()) {
            if(len<=( i-prefix[sum] )) {
                len=i-prefix[sum] ;
                st=prefix[sum]+1;
                en=i;
            }
        }else {
            prefix[sum]=i;
        }
    }
    return len;
}
int submatrixZeroSum(int n,int m,vector<v_i> v) {
    vector<int> temp(n);
    vector<v_i> prefix(n,vector<int>(m));

    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		if(j==0) prefix[i][j]=v[i][j];
    		else  prefix[i][j]=prefix[i][j-1]+v[i][j];
    	}
    }
    int curr_max,absolute_max;
    curr_max=absolute_max=0;
    int s,e,st,se;
    int left,right;
    left=right=0;
    s=e=st=se=0;
    for(int i=0;i<m;i++) {
        for(int j=i;j<m;j++) {
              for(int k=0;k<n;k++) {
                  temp[k]=prefix[k][j]-prefix[k][i]+v[k][i];
              }

              int len = maximumSubArrayZeroSum(temp,n,st,se);
              if(len > 0) {
              curr_max=(j-i+1)*(se-st+1);
              if(absolute_max < curr_max) {
                 absolute_max=curr_max;
                 left=i;
                 right=j;
                 s=st;
                 e=se;
              }
           }
        }
    }
    for(int i=s;i<=e;i++) {
     	for(int j=left;j<=right;j++) {
    		cout<<v[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return absolute_max;
}
void solve() {
    int n,m;
    cin>>n>>m; 
    std::vector<int> tmp(m);
    vector<v_i> v(n,vector<int> (m));
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		cin>>v[i][j];
    	}
    }
    cout<<submatrixZeroSum(n,m,v);
}


int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
   }
    return 0;
}




// //input
//      1
//      4 4
//      9 7 16 5 1 -6 -7 3 1 8 7 9 7 -2 0 10
//  // output
//       -6 -7 
//       8 7 
//       -2 0 
   // area
//       6




