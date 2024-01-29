class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low,mid,high;
        mid=0;
        low=mid;
        high=nums.size()-1;
        while(low<high && mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};