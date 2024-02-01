class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
    unordered_map<int,int> mp;
    int count=0;
    mp[0]=1;
    for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        int temp=presum-k;
        count+=mp[temp];
        mp[presum]+=1;
    }
    return count;
    }
};