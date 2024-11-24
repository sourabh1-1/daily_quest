class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        long long sum=0;
        int neg=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]<0)
                    neg++;
                int absVal=abs(matrix[i][j]);
                sum+=absVal;
                mini=min(mini, absVal);
            }
        }
        if(neg%2==0)
            return sum;
        return sum-2*mini;
    }
};