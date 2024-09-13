class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr.size());
        pre[0]=arr[0];
        for(int i=1;i<arr.size();i++)
            pre[i]=pre[i-1]^arr[i];
        vector<int> res(queries.size());
        int i=0;
        for(auto query: queries){
            int l=query[0];
            int r=query[1];
            if(l==0)
                res[i]=pre[r];
            else
                res[i]=pre[r]^pre[l-1];
            i++;
        }
        return res;
    }
};