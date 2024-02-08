class Solution {
public:
    int maxi(vector<int> v){
        int maxi=INT_MIN;
        for(int i=0;i<v.size();i++){
            maxi=max(maxi, v[i]);
        }
        return maxi;
    }
    int totalHour(vector<int> v, int hours, int h){
        long long totalTime=0;
        for(int i=0;i<v.size();i++){
            totalTime+=ceil((double)(v[i])/(double)(hours));
        }
        if(totalTime>h)
            return 0;
        return 1;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int n=v.size();
        int low=1;
        int high=maxi(v);
        while(low<=high){
            int mid=(high+low)/2;
            int th=totalHour(v, mid, h);
            if(th==0)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};