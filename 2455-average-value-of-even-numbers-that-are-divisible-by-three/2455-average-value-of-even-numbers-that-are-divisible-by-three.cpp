class Solution {
public:
    int averageValue(vector<int>& nums) {
        long long sum=0;
        long long count=0;
        for(auto x: nums){
            if(x%2==0 && x%3==0){
                count++;
                sum+=x;
            }
        }
        if(count==0)
            return 0;
        return sum/count;
    }
};