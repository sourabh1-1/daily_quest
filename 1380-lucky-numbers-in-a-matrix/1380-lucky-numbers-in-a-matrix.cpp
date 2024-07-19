class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        vector<int> maxCol(n);
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<m;j++)
                maxi=max(maxi, matrix[j][i]);
            maxCol[i]=maxi;
        }
        vector<int> minRow(m);
        for(int i=0;i<m;i++){
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                mini=min(mini, matrix[i][j]);
            }
            minRow[i]=mini;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(minRow[i]==maxCol[j])
                    ans.push_back(minRow[i]);
            }
        }
        return ans;
    }
};