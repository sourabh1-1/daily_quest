class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, n;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                p.push_back(nums[i]);
            else
                n.push_back(nums[i]);
        }
        for(int i=0;i<p.size();i++){
            nums[2*i]=p[i];
            nums[2*i+1]=n[i];
        }
        return nums;
    }
};