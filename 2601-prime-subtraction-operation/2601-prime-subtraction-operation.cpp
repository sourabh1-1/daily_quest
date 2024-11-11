class Solution {
public:
    int getMaxElement(vector<int>& nums) {
        int maxi=-1;
        for(int num: nums){
            if(num>maxi)
                maxi=num;
        }
        return maxi;
    }
    bool primeSubOperation(vector<int>& nums) {
        int maxEl=getMaxElement(nums);
        vector<bool> s(maxEl+1, true);
        s[1]=false;
        for(int i=2;i<=sqrt(maxEl+1);i++){
            if(s[i]){
                for(int j=i*i;j<=maxEl;j+=i)
                    s[j]=false;
            }
        }
        int curr=1;
        int i=0;
        while(i<nums.size()){
            int diff=nums[i]-curr;
            if(diff<0){
                return false;
            }
            if(s[diff]==true || diff==0){
                i++;
                curr++;
            }
            else
                curr++;
        }
        return true;
    }
};