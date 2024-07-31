class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxi=0;
        int maxVal=-1;
        for(auto x: mp){
            if(x.second>maxi){
                maxVal=x.first;
                maxi=x.second;
            }
        }
        return maxVal;
    }
};