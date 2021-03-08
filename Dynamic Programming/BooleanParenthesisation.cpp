#define mod 1003
int countWays(int N, string S){
        // code here
        string s1,s2;
        for(int i=0;i<N;i++) {
            if(i%2==0) s1.push_back(S[i]);
            else s2.push_back(S[i]);
        }
        int len=s1.length();
        long long  T[len][len],F[len][len];
      //  cout<<F[0][len-1]<<endl;
       for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++) {
                T[i][j]=F[i][j]=0;
            }
            
        }
        for(int i=0;i<len;i++) {
            if(s1[i]=='T') T[i][i]=1;
            else T[i][i]=0;
        }
        for(int i=0;i<len;i++) {
            if(s1[i]=='F') F[i][i]=1;
            else F[i][i]=0;
          
        }

        for(int g=1;g<len;g++) {
            int i=0;
            int j=g;
            while(j<len) {
                T[i][j]=F[i][j]=0;
                for(int k=i;k<j;k++) { 
                  if(s2[k]=='&')   {
                      T[i][j]=(T[i][j]+T[i][k]*T[k+1][j])%mod;
                      F[i][j]=(F[i][j]+T[i][k]*F[k+1][j]+F[i][k]*F[k+1][j]+F[i][k]*T[k+1][j])%mod;
                  }
                  else if(s2[k]=='|')   {
                      T[i][j]=(T[i][j]+T[i][k]*F[k+1][j]+T[i][k]*T[k+1][j]+F[i][k]*T[k+1][j])%mod;
                      F[i][j]=(F[i][j]+F[i][k]*F[k+1][j])%mod;
                  }
                  else if(s2[k]=='^')   {
                      T[i][j]=(T[i][j]+T[i][k]*F[k+1][j]+F[i][k]*T[k+1][j])%mod;
                      F[i][j]=(F[i][j]+F[i][k]*F[k+1][j]+T[i][k]*T[k+1][j])%mod;
                  }
                 
            }
             i++;j++;
            
        }
        
       
    }
     return (int)T[0][len-1];
    }
