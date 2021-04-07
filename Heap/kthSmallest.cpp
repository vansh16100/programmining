int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> Q;
  Q.push({mat[0][0],{0,0}});
  while(k>1) {
      auto tmp=Q.top();
      Q.pop();
      pair<int,int> j=tmp.second;
      k--;
      if(j.first<n-1) Q.push({mat[j.first+1][j.second],{j.first+1,j.second}});
      if(j.first==0&&j.second<n-1) Q.push({mat[j.first][j.second+1],{j.first,j.second+1}});
  }
  return Q.top().first;
}