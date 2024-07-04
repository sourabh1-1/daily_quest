class Solution {
private:
    int topDown(int m, int n, vector<vector<int>> &dp){
        if(m==0 && n==0)
            return 1;
        if(m<0 || n<0)
            return 0;
        if(dp[m][n]!= -1)
            return dp[m][n];
        int up=topDown(m-1, n, dp);
        int left=topDown(m, n-1, dp);
        return dp[m][n]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return topDown(m-1, n-1, dp);
        
        // tabulation ie. bottom-up
        dp[0][0]=1;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 && c==0)
                    continue;
                else{
                    int up=0;
                    int left=0;
                    if(r>0)
                        up=dp[r-1][c];
                    if(c>0)
                        left=dp[r][c-1];
                    dp[r][c]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};