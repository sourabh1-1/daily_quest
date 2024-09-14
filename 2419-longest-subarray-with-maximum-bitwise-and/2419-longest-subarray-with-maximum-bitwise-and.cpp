class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val=nums[0];
        int len=1;
        int max_len=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==max_val){
                len++;
                max_len=max(max_len, len);
            }
            else if(nums[i]>max_val){
                max_val=nums[i];
                len=1;
                max_len=1;
            }
            else
                len=0;
        }
        return max_len;
    }
};