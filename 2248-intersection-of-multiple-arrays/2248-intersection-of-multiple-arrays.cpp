class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,int> mp;
        vector<int> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                mp[nums[i][j]]++;
            }
        }
        for(auto x:mp){
            if(x.second==n)
                result.push_back(x.first);
        }
        return result;
    }
};