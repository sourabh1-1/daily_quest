class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum=*max_element(prices.begin(),prices.end());
        int profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minimum)
                minimum=prices[i];
            if(profit<prices[i]-minimum)
                profit=prices[i]-minimum;
        }
        return profit;
    }
};