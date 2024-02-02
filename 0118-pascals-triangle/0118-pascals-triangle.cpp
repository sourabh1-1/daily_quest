class Solution {
public:
    vector<int> generateRow(int row){
        long long res=1;
        vector<int> v;
        v.push_back(res);
        for(int j=1;j<row;j++){
            res=res*(row-j);
            res=res/j;
            v.push_back(res);
        }
        return v;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};