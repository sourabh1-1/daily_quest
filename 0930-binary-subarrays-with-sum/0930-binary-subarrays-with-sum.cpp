class Solution {
public:
    int numberOfSubarray(vector<int>& nums, int goal){
        if(goal<0)
            return 0;
        int count=0;
        int n=nums.size();
        int sum=0;
        int start=0;
        int end=0;
        while(end<n){
            sum+=nums[end];
            while(sum>goal && start<=end){
                sum-=nums[start];
                start++;
            }
            count=count+(end-start+1);
            end++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1=numberOfSubarray(nums, goal);
        int count2=numberOfSubarray(nums, goal-1);
        return count1-count2;
    }
};