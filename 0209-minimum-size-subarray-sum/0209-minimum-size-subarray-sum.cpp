class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,start=0;
        int result=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                return 1;
            sum+=nums[i];
            while(sum>=target){
                result=min(result,i-start+1);
                sum-=nums[start];
                start++;
            }
        }
        return result==INT_MAX?0:result;
    }
};