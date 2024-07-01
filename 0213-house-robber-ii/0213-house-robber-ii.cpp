class Solution {
private:
    int fun(vector<int> &nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i]+prev2;
            int noPick=0+prev;
            int curr=max(pick, noPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1)
                temp1.push_back(nums[i]);
            if(i!=0)
                temp2.push_back(nums[i]);
        }
        return max(fun(temp1), fun(temp2));
    }
};