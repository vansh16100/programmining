#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(int N, int arr[])
{
    // code here
    int dp[N + 1][N + 1];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int l = 1; l <= N - 1; l++)
    {
        int i = 1;
        int j = i + l - 1;
        while (j < N)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int res = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], res);
                }
            }
            i++;
            j++;
        }
    }
    return dp[1][N - 1];
}

int main() {
    cout<<"enter a number\n";
    int n;
    cin>>n;
    cout<<"no of elements is "<<n-1<<"\n";
    int arr[n+1];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<matrixMultiplication(n,arr);
}

/* input 
3
1 2 3
output
6
*/