class schedule {
public:
   int start,end,profit;
};
bool myCmp(schedule x,schedule y) {
     return x.end < y.end;
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         int x=startTime.size();
         vector<schedule> profitx(x);
         for(int i=0;i<x;i++) {
              profitx[i].start=startTime[i];
              profitx[i].end=endTime[i];
              profitx[i].profit=profit[i];
        }
        sort(profitx.begin(),profitx.end(),myCmp);
        
        int dp[x];
        for(int i=0;i<x;i++) {
             dp[i] = profitx[i].profit;
         }
        
        for(int i=0;i<x;i++) {
            for(int j=0;j<i;j++) {
                if(profitx[i].start>=profitx[j].end) {
                    dp[i]=max( dp[j] + profitx[i].profit , dp[i] );
                }
            }
        }
        return *max_element(dp,dp+x)
        
    }
int main(){
    int n;
    cin>>n;
    vector<int> startingTime(n),endingTime(n),profit(n);
    for(int i=0;i<n;i++) cin>>startingTime[i];
    for(int i=0;i<n;i++) cin>>endingTime[i];
    for(int i=0;i<n;i++) cin>>profit[i];
    cout<<jobScheduling(startingTime,endingTime.profit);
}
