class Solution {
    int countNumber(int prefix, int n) {
        long long first=prefix, next=prefix+1;
        int total=0;
        while(first<=n){
            total+=static_cast<int>(min(n+1LL, next)-first);
            first*=10;
            next*=10;
        }
        return total;
    }
public:
    int findKthNumber(int n, int k) {
        int curPre=1;
        --k;
        while(k>0){
            int count=countNumber(curPre, n);
            if(k>=count){
                ++curPre;
                k-=count;
            } 
            else{
                curPre*=10;
                --k;
            }
        }
        return curPre;
    }
};