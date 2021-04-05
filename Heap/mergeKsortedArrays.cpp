////  complexity = O(n*k*logk)

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    //code here
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
    for (int i = 0; i < k; i++)
    {
        p.push(make_pair(arr[i][0], make_pair(i, 0)));
    }
    vector<int> v(k * k);
    int index = 0;
    while (!p.empty())
    {
        auto it = p.top();
        p.pop();
        v[index++] = it.first;
        int i = it.second.first;
        int j = it.second.second;
        if (j < k - 1)
        {
            p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
        }
    }

    return v;
}
//   complexity = O(n*k*logk)
// recursive approach
void merge(vector<int> &a,int al,vector<int> &b,int bl,vector<int> &c) {
    int i,j,k;
    i=j=k=0;
    while(i<al && j<bl) {
        if(a[i]<b[j]) c[k++] = (a[i++]);
        else c[k++]  = (b[j++]);
    }
    while(i<al) {
         c[k++]  = (a[i++]);
    }
    while(j<bl) {
         c[k++]  = (b[j++]);
    }
    
}
void mergeK(vector<vector<int>>& arr,int s,int e,int k,vector<int> &output) {
    if(s>e) return ;
    if(s==e) {
        int index=0;
        for(int i=0;i<k;i++) {
            output[index++] = (arr[s][i]);
        }
        return;
    } 
    if(e-s==1) {
        merge(arr[s],k,arr[e],k,output);
        return ;
    }
    int mid = (s+e)/2;  
    
    vector<int> output1(k*(mid-s+1)),output2(k*(e-mid));

    mergeK(arr,s,mid,k,output1);
    mergeK(arr,mid+1,e,k,output2);
    merge(output1,k*(mid-s+1),output2,k*(e-mid),output);
}
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
    vector<int> v(k*k);
      mergeK(arr,0,k-1,k,v);
      return v;
    }
};
