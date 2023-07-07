class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag1=-1;
        int flag2=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag1=i;
                break;
            }
        }
        if(flag1==-1)
            reverse(nums.begin(),nums.end());
        else{
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]>nums[flag1]){
                    flag2=i;
                    break;
                }
            }
            swap(nums[flag1],nums[flag2]);
            reverse(nums.begin()+flag1+1,nums.end());
        }
    }
};