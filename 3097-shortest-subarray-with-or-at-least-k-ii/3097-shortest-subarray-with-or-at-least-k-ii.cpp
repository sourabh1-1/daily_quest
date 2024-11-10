class Solution {
private:
    void setBit(vector<int> &bits, int num, int val){
        for(int i=0;i<32;i++){
            if((num>>i) & 1)
                bits[i]+=val;
        }
    }
    int getVal(vector<int> &bits){
        int ans=0;
        for(int i=0;i<32;i++){
            if(bits[i]>0){
                ans |=(1<<i);
            }
        }
        return ans;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int end=0;
        int minLen=INT_MAX;
        vector<int> bits(32, 0);
        while(end<n){
            setBit(bits, nums[end], 1);
            while(start<=end && getVal(bits)>=k){
                minLen=min(minLen, end-start+1);
                setBit(bits, nums[start], -1);
                start++;
            }
            end++;
        }
        return minLen==INT_MAX?-1:minLen;
    }
};