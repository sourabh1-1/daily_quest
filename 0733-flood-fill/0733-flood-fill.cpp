class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color)
            return image;
        queue<pair<int,int>> q;
        int temp=image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int addrow[]={0,-1,0,1};
            int addcol[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr=r+addrow[i];
                int nc=c+addcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==temp){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};