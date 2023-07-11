class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        
        int i=1;
        while(i<=n){
            if(s.find(i)!=s.end())
                i++;
            else
                return i;
        }
        return n+1;
    }
};