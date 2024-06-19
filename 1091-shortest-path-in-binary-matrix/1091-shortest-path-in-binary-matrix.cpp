class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n=grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        if(grid[0][0]==0)
            q.push({1, {0,0}});
        else 
            return -1;
        dist[0][0]=1;
        int drow[]={-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[]={-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    // if(nrow==n-1 && ncol==n-1)
                    //     return dis+1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        if(dist[n-1][n-1]!=INT_MAX)
            return dist[n-1][n-1];
        return -1;
    }
};