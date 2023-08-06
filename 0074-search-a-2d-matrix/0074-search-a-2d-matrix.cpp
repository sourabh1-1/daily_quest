class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int s=0;
        int e=r*c-1;
        while(s<=e){
            int m=(s+e)/2;
            int midval=matrix[m/c][m%c];
            if(midval==target)
                return true;
            if(midval<target)
                s=m+1;
            else
                e=m-1;
        }
        return false;
    }
};