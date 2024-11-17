class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int size=INT_MAX;
        long long curr_sum=0;
        deque<pair<long long, int>> q;
        for(int e=0;e<nums.size();e++){
            curr_sum+=nums[e];
            if(curr_sum>=k)
                size=min(size, e+1);
            while(!q.empty() && curr_sum-q.front().first>=k){
                auto [preSum, ind]=q.front();
                size=min(size, e-ind);
                q.pop_front();
            }
            while(!q.empty() && q.back().first>curr_sum)
                q.pop_back();
            q.push_back({curr_sum, e});
        }
        return size==INT_MAX?-1:size;
    }
};