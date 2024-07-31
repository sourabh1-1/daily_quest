class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int count=1;
        int j=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[j]){
                j++;
                count++;
                nums[j]=nums[i];
            }
        }
        return count;
    }
};