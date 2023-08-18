class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size()-1;
        while(j<=n){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;j++;
            }
            else if(nums[j]==2){
                swap(nums[j],nums[n]);
                n--;
            }
            else
                j++;
        }
    }
};