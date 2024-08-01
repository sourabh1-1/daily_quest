class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            int newBottles=numBottles/numExchange;
            int remaining=numBottles%numExchange;
            ans+=newBottles;
            numBottles=newBottles+remaining;
        }
        return ans;
    }
};