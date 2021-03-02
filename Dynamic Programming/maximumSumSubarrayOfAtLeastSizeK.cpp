/////...this file only contains function that takes the the array and the value K it
//// is strongly recommended to make your own main function

long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
{   
    long long tmp[n];
    tmp[0]=arr[0];
    
    long long int currMax=arr[0];
    for(int i=1;i<n;i++) {
        if(currMax<0) currMax=0;
        currMax+=arr[i];
        tmp[i]=currMax;
    }
    
    long long sumOfk=0;
   for(int i=0;i<k;i++) {
       sumOfk+=arr[i];
   }
 
   long long int actualMax=sumOfk;
   long long curr_sum=sumOfk;
   for(int i=k;i<n;i++) {
       sumOfk+=arr[i];
       sumOfk-=arr[i-k];
    
       curr_sum=max(tmp[i-k]+sumOfk,sumOfk);
       actualMax=max(actualMax,curr_sum);
   }
   return actualMax;
}
