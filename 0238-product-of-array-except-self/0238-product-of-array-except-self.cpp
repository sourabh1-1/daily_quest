class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        output[0] = 1;
        for(int i=1; i<nums.size(); i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=nums.size()-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};