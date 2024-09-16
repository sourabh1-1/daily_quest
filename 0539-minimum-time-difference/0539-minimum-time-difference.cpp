class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> mins(n);
        for(int i=0;i<n;i++){
            int h=stoi(timePoints[i].substr(0, 2));
            int m=stoi(timePoints[i].substr(3));
            mins[i]=h*60+m;
        }
        int mini=INT_MAX;
        sort(mins.begin(), mins.end());
        for(int i=0;i<n-1;i++){
            mini=min(mini, mins[i+1]-mins[i]);
        }
        mini=min(mini, 24*60-(mins[n-1]-mins[0]));
        return mini;
    }
};