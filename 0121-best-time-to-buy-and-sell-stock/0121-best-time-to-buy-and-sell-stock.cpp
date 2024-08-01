class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<mini)
                mini=prices[i];
            if(profit<prices[i]-mini){
                profit=prices[i]-mini;
            }
        }
        return profit;
    }
};