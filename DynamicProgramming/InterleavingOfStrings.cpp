bool isInterleave(string A, string B, string C) 
{
    //Your code here
    int aLen=A.length();
    int bLen=B.length();
    bool dp[aLen+1][bLen+1];
    for(int i=0;i<=aLen;i++) {
        for(int j=0;j<=bLen;j++) {
            dp[i][j]=false;
        }
    }
    dp[0][0]=true;
    for(int i=1;i<=bLen;i++) {
        if(B[i-1]==C[i-1]) dp[0][i]=dp[0][i-1];
        else dp[0][i]=false;
    }
     for(int i=1;i<=aLen;i++) {
        if(A[i-1]==C[i-1]) dp[i][0]=dp[i-1][0];
        else dp[i][0]=false;
    }
    
    for(int i=1;i<=aLen;i++) {
        for(int j=1;j<=bLen;j++) {
            if(C[i+j-1]==A[i-1]) dp[i][j]=dp[i-1][j];
            if(C[i+j-1]==B[j-1]) dp[i][j]=dp[i][j]||dp[i][j-1];
        }
    }
    
    return dp[aLen][bLen];
}
