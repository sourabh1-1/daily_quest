class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k<0)
            return 0;
        int start=0;
        int end=0;
        int count=0;
        int subArray=0;
        while(end<nums.size()){
            if(nums[end]%2==1)
                count++;
            while(count>k){
                if(nums[start]%2==1)
                    count-=1;
                start++;
            }
            subArray+=(end-start+1);
            end++;
        }
        return subArray;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count1=helper(nums, k);
        int count2=helper(nums, k-1);
        return count1-count2;
    }
};