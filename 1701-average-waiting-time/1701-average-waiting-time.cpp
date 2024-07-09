class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int size=customers.size();
        double totalTime=customers[0][0]+customers[0][1];
        double totalWait=customers[0][1];
        for(int i=1;i<size;i++){
            int wait=0;
            int arrived=customers[i][0];
            int idle = (arrived > totalTime) ? (arrived - totalTime) : 0;
            totalTime+=customers[i][1]+idle;
            wait=totalTime-arrived;
            totalWait+=wait;
        }
        return totalWait/size;
    }
};