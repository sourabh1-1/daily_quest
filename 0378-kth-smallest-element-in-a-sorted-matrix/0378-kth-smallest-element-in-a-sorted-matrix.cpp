class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        priority_queue<int> maxHeap;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                maxHeap.push(matrix[i][j]);
                if(maxHeap.size()>k)
                    maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};