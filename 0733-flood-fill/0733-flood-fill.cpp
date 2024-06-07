class Solution {
private:
    void dfs(int sr, int sc, int initcolor, vector<vector<int>>&res, vector<vector<int>> image, int drow[], int dcol[], int newColor, int n, int m){
        res[sr][sc]=newColor;
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initcolor && res[nrow][ncol]!=newColor){
                dfs(nrow, ncol, initcolor, res, image, drow, dcol, newColor, n, m);
            }
        }
    } 
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> res=image;
        int initcolor=image[sr][sc];
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        int n=image.size();
        int m=image[0].size();
        dfs(sr,sc,initcolor, res, image, drow, dcol, color, n, m);
        return res;
    }
};