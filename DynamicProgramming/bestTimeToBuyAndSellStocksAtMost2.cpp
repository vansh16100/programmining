//this file only contains the function that return the maximum profit

// time complexity = O(n)
 int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix(n,0),suffix(n,0);
        int max1=0;
        int uptil_now_max=prices[n-1];
        for(int i=n-2;i>=0;i--) {
            if(prices[i]>uptil_now_max)
                uptil_now_max = prices[i];
            if(prices[i]<uptil_now_max)
                max1=max(max1,uptil_now_max-prices[i]);
             suffix[i] = max1;
        }
       
        max1=0;
        int uptil_now_min=prices[0];
        for(int i=0;i<n;i++) {
            if(prices[i]<uptil_now_min)
                uptil_now_min = prices[i];
            if(prices[i]>uptil_now_min)
                max1=max(max1,prices[i]-uptil_now_min);
            prefix[i] = max1;
        }
        max1=0;
        for(int i=0;i<n;i++) {
           max1=max(max1,prefix[i]+suffix[i]);
      }
        return max1;
    }
