class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
        return 0;
    int maxi=1;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(nums[i]);
    }
    for(auto it: s){
        if(s.find(it-1)==s.end()){
            int count=1;
            int x=it;
            while(s.find(x+1)!=s.end()){
                x=x+1;
                count++;
            }
            maxi=max(maxi,count);
        }
    }
    return maxi;
    }
};