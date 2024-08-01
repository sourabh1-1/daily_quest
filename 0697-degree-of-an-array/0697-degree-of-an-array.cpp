class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        map<int, int> freq;
        map<int, int> first;
        map<int, int> last;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(first.find(nums[i])==first.end())
                first[nums[i]]=i;
            last[nums[i]]=i;
        }
        int maxi=INT_MIN;
        for(auto it: freq){
            maxi=max(maxi, it.second);
        }
        int mini=INT_MAX;
        for(auto it: freq){
            if(it.second==maxi){
                int len=last[it.first]-first[it.first]+1;
                mini=min(mini, len);
            }
        }
        return mini;
    }
};