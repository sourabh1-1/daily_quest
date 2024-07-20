class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int maxi=0;
        int l=0;
        int r=0;
        int n=s.size();
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            maxi=max(maxi, r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxi;
    }
};