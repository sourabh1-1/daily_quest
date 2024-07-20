class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int, int> mp;
        int start=0;
        int end=0;
        int maxLen=0;
        int maxf=0;
        int n=s.size();
        while(end<n){
            mp[s[end]]++;
            maxf=max(maxf, mp[s[end]]);
            if((end-start+1)-maxf>k){
                mp[s[start]]--;
                start++;
            }
            maxLen=max(maxLen, end-start+1);
            end++;
        }
        return maxLen;
    }
};