class Solution {
private:
    void dfs(int r, int c, vector<vector<char>> board, vector<vector<int>> &vis, int drow[], int dcol[]){
        vis[r][c]=1;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, board, vis, drow, dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        // vector<vector<char>> res(m, vector<char>(n,'X'));
        vector<vector<int>> vis(m, vector<int>(n,0));
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                vis[0][j]=1;
                dfs(0, j, board, vis, drow, dcol);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                vis[m-1][j]=1;
                dfs(m-1, j, board, vis, drow, dcol);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                vis[i][0]=1;
                dfs(i, 0, board, vis, drow, dcol);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                vis[i][n-1]=1;
                dfs(i, n-1, board, vis, drow, dcol);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j])
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};