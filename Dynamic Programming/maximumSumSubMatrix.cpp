int kadane(vector<int> v,int n) {
       int curr_max,absolute_max;
       curr_max=absolute_max=0;
       for(int i=0;i<n;i++) {
       	curr_max+=v[i];
       	if(curr_max<0) curr_max=0;
       	absolute_max=max(curr_max,absolute_max);
       }
       return absolute_max;
}
int maximumSum(int n,int m,vector<v_i> v) {
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
    for(int i=0;i<m;i++) {
        for(int j=i;j<m;j++) {
              for(int k=0;k<n;k++) {
                  temp[k]=prefix[k][j]-prefix[k][i]+v[k][i];
              }
              curr_max=kadane(temp,n);
              absolute_max=max(absolute_max,curr_max);
        }
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
    cout<<maximumSum(n,m,v)<<"\n";
}
