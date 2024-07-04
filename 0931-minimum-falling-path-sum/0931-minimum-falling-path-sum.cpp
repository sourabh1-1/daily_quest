class Solution {
private:
    int memoiation(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp){
        if(j<0 || j>=n)
            return 1e9;
        if(i==0)
            return matrix[0][j];
        if(dp[i][j]!= 1e9)
            return dp[i][j];
        int up=matrix[i][j]+memoiation(i-1, j, matrix, n, dp);
        int diagLeft=matrix[i][j]+memoiation(i-1, j-1, matrix, n, dp);
        int diagRight=matrix[i][j]+memoiation(i-1, j+1, matrix, n, dp);
        
        return dp[i][j]=min(up, min(diagLeft, diagRight));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=1e9;
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int c=0;c<n;c++)
            mini=min(mini, memoiation(n-1, c, matrix, n, dp));
        return mini;
    }
};