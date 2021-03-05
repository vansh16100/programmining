 int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        bool dp[n][n];
        for(int i=0;i<n;i++) dp[i][i]=true;
        for(int i=0;i<n-1;i++) {
            if(str[i]==str[i+1]) dp[i][i+1]=true;
            else dp[i][i+1]=false;
        }
        for(int g=2;g<n;g++) {
            int i=0;
            int j=g;
            while(j<n) {
                if(str[i]==str[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=false;
                i++;j++;
            }
        }
      
        int minCuts[n+1];
        minCuts[0]=-1;
        minCuts[1]=0;
        if(str[1]==str[0]) minCuts[2]=0;
        else minCuts[2]=1;
        
        for(int i=3;i<=n;i++) {
            int res=INT_MAX;
            for(int j=0;j<i;j++){
            string tmp=str.substr(j,i-j);
            if(dp[j][i-1]) {
                res=min(res,minCuts[j]);
              }
            }
            minCuts[i]=res+1;
        }
       
        return minCuts[n];
    }
