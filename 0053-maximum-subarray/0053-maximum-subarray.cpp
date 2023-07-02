class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum<nums[i])
                sum=nums[i];
            if(sum>max)
                max=sum;
        }
        return max;
    }
};