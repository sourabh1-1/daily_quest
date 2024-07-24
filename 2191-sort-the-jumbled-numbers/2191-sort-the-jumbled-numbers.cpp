class Solution {
public:
    void mapped(int val, int &mapVal, vector<int> mapping){
        int r=val%10;
        val=val/10;
        if(val>0){
            mapped(val, mapVal, mapping);
        }
        mapVal=mapVal*10+mapping[r];
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mapValue;
        for(auto x: nums){
            int mapVal=0;
            mapped(x, mapVal, mapping);
            mapValue[x]=mapVal;
        }
        sort(nums.begin(), nums.end(), [&mapValue](int a, int b){
            return mapValue[a]<mapValue[b];
        });
        return nums;
    }
};