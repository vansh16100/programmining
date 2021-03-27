vector<pair<int,int>> v= {{0,1},{0,-1},{1,1},{1,-1},{1,0},{-1,1},{-1,0},{-1,-1}};
void dfs(vector<vector<char>>& grid,int i,int j,int row,int col) {
    if(i>=row || i<0 || j<0 || j>=col || grid[i][j]=='0') return;
    
    grid[i][j] = '0';
    for(int k=0;k<8;k++) {
        dfs(grid,i+v[k].first,j+v[k].second,row,col);
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int c=0;
        for(int i = 0;i<row;i++) {
            for(int j = 0;j<col;j++) {
                if(grid[i][j]=='1') {
                    dfs(grid,i,j,row,col);
                    c++;
                }
            }
        }
        return c;
    }
};