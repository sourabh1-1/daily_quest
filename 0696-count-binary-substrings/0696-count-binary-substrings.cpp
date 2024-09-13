class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int curr=1;
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                prev=curr;
                curr=1;
            }
            else
                curr++;
            if(prev>=curr)
                ans++;
        }
        return ans;
    }
};