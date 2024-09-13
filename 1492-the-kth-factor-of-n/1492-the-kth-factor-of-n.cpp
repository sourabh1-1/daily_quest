class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factor;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0 && i*i!=n){
                factor.push_back(i);
                factor.push_back(n/i);
            }
            else if(n%i==0)
                factor.push_back(i);
        }
        sort(factor.begin(), factor.end());
        if(factor.size()<k)
            return -1;
        return factor[k-1];
    }
};