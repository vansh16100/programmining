#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

void heapify(int arr[],int n,int i ) {
    int maxi = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n&&arr[maxi]<arr[left]) maxi = left;
    if(right<n&&arr[maxi]<arr[right]) maxi = right;
    if(maxi!=i) {
        swap(arr[i],arr[maxi]);
        heapify(arr,n,maxi);
    }
}

void buildHeap(int arr[],int n) {
    for(int i=n/2;i>=0;i--) {
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n) {
   for(int i=0;i<n;i++) {
       swap(arr[0],arr[n-i-1]);
       heapify(arr,n-i-1,0);
   }
}
void solve() {
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++) cin>>arr[i];
     buildHeap(arr,n);
     heapSort(arr,n);
     for(int i=0;i<n;i++) {
         cout<<arr[i]<<" ";
     }
     cout<<"\n";
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("E:/competitive/input.txt", "r", stdin);
//     freopen("E:/competitive/output.txt", "w", stdout);
// #endif
// int t;
// cin>>t;
// while(t--){
solve();
//   }
return 0;
 }