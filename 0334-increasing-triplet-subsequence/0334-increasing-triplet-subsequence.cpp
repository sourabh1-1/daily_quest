class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int count=1;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
                count++;
            }
            else{
                int it=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[it]=nums[i];
            }
        }
        if(count>2)
            return true;
        return false;
    }
};