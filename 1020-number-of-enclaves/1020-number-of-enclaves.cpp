class Solution {
private:
    void dfs(int r, int c, vector<vector<int>> &grid, int m, int n){
        int drow[]={-1, 0, 0, 1};
        int dcol[]={0, -1, 1, 0};
        grid[r][c]=-1;
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                dfs(nrow, ncol, grid, m, n);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0; 
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)
                dfs(0, j, grid, m, n);
            if(grid[m-1][j]==1)
                dfs(m-1, j, grid, m, n);
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)
                dfs(i, 0, grid, m, n);
            if(grid[i][n-1]==1)
                dfs(i, n-1, grid, m, n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};