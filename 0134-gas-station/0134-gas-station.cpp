class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int reqGas=0;
        int ans=0;
        for(int i=0;i<gas.size();i++){
            totalGas+=gas[i]-cost[i];
            reqGas+=gas[i]-cost[i];
            if(totalGas<0){
                totalGas=0;
                ans=i+1;
            }
        }
        return reqGas<0?-1: ans;
    }
};